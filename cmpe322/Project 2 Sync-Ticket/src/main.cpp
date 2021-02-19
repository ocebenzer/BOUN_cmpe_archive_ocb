#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <thread>
#include <mutex>
#include <queue>
#include <list>

/*
2017400048 Omer Cihan Benzer omer.benzer@boun.edu.tr
*/

using namespace std;

struct client {
    string name;
    int arrival_time{}, service_time{}, seat_number{};
};
/*
auto start = chrono::steady_clock::now();
string timer(){
    using namespace chrono;
    auto now = steady_clock::now();
    return " | Clock is: " + to_string(duration_cast<milliseconds>(now - start).count()) + "ms";
}
*/
mutex output_mutex, queue_mutex, seat_mutex, counter_mutex;
vector<string> theater_seats;
int client_amount;
int client_counter = 0;
bool tellers_available[] = {true, true, true};
client *clients;
queue<client, list<client>> client_queue;

bool tellerFirstToServe(int teller_id) {
    for (int i = 0; i < teller_id; i++) {
        if (tellers_available[i]) return false;
    }
    return true;
}

void teller_thread(int teller_id, ofstream &outputFile) {
    this_thread::sleep_for(chrono::milliseconds(teller_id));
    string teller_name = "Teller ";
    teller_name.push_back('A' + teller_id); // append A, B, C depending on i

    client current_client;

    output_mutex.lock();
    outputFile << teller_name << " has arrived." << endl;
    cout << "(T) " << teller_name << " has arrived." << endl;
    output_mutex.unlock();

    counter_mutex.lock(); // This counter_mutex is required since otherwise, other threads can edit the counter before checking while condition 
    while (client_counter < client_amount) {
        counter_mutex.unlock();

        queue_mutex.lock();
        // If there is a more privileged teller or there is no client, go to sleep
        if (!tellerFirstToServe(teller_id) || client_queue.empty()) {
            queue_mutex.unlock();
            this_thread::sleep_for(chrono::milliseconds(1));
            continue;
        }
        // if teller will serve, get the client and handle it as needed
        tellers_available[teller_id] = false;
        current_client = client_queue.front();
        client_queue.pop();
        queue_mutex.unlock();

        // Handle seat no of the client
        int reserved_seat = 0;
        seat_mutex.lock();
        if (theater_seats[current_client.seat_number - 1].empty()) {
            reserved_seat = current_client.seat_number;
            theater_seats[current_client.seat_number - 1] = current_client.name;
        } else {
            for (int i = 0; i < theater_seats.size(); i++) {
                if (theater_seats[i].empty()) {
                    reserved_seat = i + 1;
                    theater_seats[i] = current_client.name;
                    break;
                }
            }
            // right now, if reserved_seat is 0, the client will reserve seat "None"
        }
        seat_mutex.unlock();

        this_thread::sleep_for(chrono::milliseconds(current_client.service_time));

        if (reserved_seat > 0) {
            output_mutex.lock();
            outputFile << current_client.name << " requests seat " << current_client.seat_number << ", reserves seat "
                       << reserved_seat << ". Signed by " << teller_name << "." << endl;
            cout << "(T) " << current_client.name << " requests seat " << current_client.seat_number
                 << ", reserves seat " << reserved_seat << ". Signed by " << teller_name << "." << endl;
            output_mutex.unlock();
        } else {
            output_mutex.lock();
            outputFile << current_client.name << " requests seat " << current_client.seat_number
                       << ", reserves None. Signed by " << teller_name << "." << endl;
            cout << "(T) " << current_client.name << " requests seat " << current_client.seat_number
                 << ", reserves None. Signed by " << teller_name << "." << endl;
            output_mutex.unlock();
        }

        tellers_available[teller_id] = true;

        counter_mutex.lock();
        client_counter++;
    }
    counter_mutex.unlock();
}

void client_thread(const client &client) {
    this_thread::sleep_for(chrono::milliseconds(client.arrival_time));

    queue_mutex.lock();
    client_queue.push(client);
    queue_mutex.unlock();
}

int main(int argc, char *argv[]) {
    if (argc != 3) return 1;

    string tmp;
    // get input-output files
    ifstream inputFile(argv[1]);
    ofstream outputFile(argv[2]);

    // read theater_name
    getline(inputFile, tmp);
    string theater_name = (tmp.back()=='\n' || tmp.back()=='\r') ? tmp.substr(0, tmp.size() - 1) : tmp;
    cout << "#" +theater_name+"#" << endl;
    if (theater_name == "OdaTiyatrosu") {
        theater_seats = vector<string>(60);
    } else if (theater_name == "UskudarStudyoSahne") {
        theater_seats = vector<string>(80);
    } else if (theater_name == "KucukSahne") {
        theater_seats = vector<string>(200);
    } else {
        cout << "INVALID INPUT FILE" << endl;
        return 1;
    }

    // read client_amount, number of clients there are
    getline(inputFile, tmp);
    client_amount = atoi(tmp.c_str());

    // read clients
    clients = new client[client_amount]();
    for (int i = 0; i < client_amount; i++) {
        getline(inputFile, tmp);
        istringstream ss(tmp);
        getline(ss, clients[i].name, ',');
        getline(ss, tmp, ',');
        clients[i].arrival_time = atoi(tmp.c_str());
        getline(ss, tmp, ',');
        clients[i].service_time = atoi(tmp.c_str());
        getline(ss, tmp, ',');
        clients[i].seat_number = atoi(tmp.c_str());
    }

    output_mutex.lock();
    outputFile << "Welcome to the Sync-Ticket!" << endl;
    cout << "(M) " << "Welcome to the Sync-Ticket!" << endl;
    output_mutex.unlock();

    //create teller threads
    thread teller_threads[3];
    for (int i = 0; i < 3; i++) {
        teller_threads[i] = thread(teller_thread, i, ref(outputFile));
    }
/*
    //Timer starts from here
    start = chrono::steady_clock::now();
*/
    // create client threads
    thread client_threads[client_amount];
    for (int i = 0; i < client_amount; i++) {
        client_threads[i] = thread(client_thread, clients[i]);
    }

    counter_mutex.lock(); // This counter_mutex is required since otherwise, other threads can edit the counter before checking while condition 
    while (client_counter < client_amount) {
        counter_mutex.unlock();

        this_thread::sleep_for(chrono::milliseconds(10));
        counter_mutex.lock();
    }
    counter_mutex.unlock();

    // exit threads
    for (thread &client : client_threads) {
        if (client.joinable()) {
            client.join();
        } else cout << "CLIENT THREAD ERROR" << endl;
    }
    for (thread &teller : teller_threads) {
        if (teller.joinable()) {
            teller.join();
        } else cout << "TELLER THREAD ERROR" << endl;
    }

    outputFile << "All clients received service." << endl;
    cout << "(M) " << "All clients received service." << endl;
    return 0;
}
