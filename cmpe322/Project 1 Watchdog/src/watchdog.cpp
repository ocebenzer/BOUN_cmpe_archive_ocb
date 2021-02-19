#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <map>
#include <string.h>
#include <unistd.h>
#include <signal.h>

using namespace std;

/**
 * @mainpage 2017400048 Ömer Cihan Benzer Cmpe 322 Project1
 *
 * This project was made before the executor update, hence the different style. I hope it is good enough.
 * - You can select the files from the "Files" bar above
 * - Note that I sent a "makefile" to ease execution, just in case it doesn't work. Typing "make" is enough.
 */




/**
 * user signal #1 that process sends to watchdog when it dies.
 * @see handle_dying_child()
 */
#define SIGNAL_CHILD_DEATH 30

/**
 * user signal #2 that watchdog sends to process in order to shut it down. @n 
 * note that this signal is different from SIGTERM as process' that are sent this signal do not return @ref SIGNAL_CHILD_DEATH to watchdog.
 * @ref SIGNAL_CHILD_DEATH is sent to watchdog in order to be handled via @ref handle_dying_child()
 * @see handle_dying_child()
 */
#define SIGNAL_KILLSELF 31

/**
 * anything written into @ref watchdog_output is also written onto console, with prefix "=>"
 * @see writefile_watchdog()
 */
#define WATCHDOG_PREFIX "=> "


/**
 * number of processes the watchdog will handle
 * @see child_ids
 */
static int num_of_process;

/**
 * path of the watchdog output
 * @see writefile_watchdog()
 */
static string watchdog_output;

/**
 * path of the process' output, included in arguments of "exec(./process.exe ...)"
 * @see create_child() 
 */
static string process_output;


/**
 * path of the instruction input
 */
static string instruction_path;

/**
 * signal handler of watchdog
 * @see handle_dying_child()
 */
static struct sigaction mysignal;

/**
 * array that stores "pid"s of children at child_ids[id-1]. @n ie. head process, P1 is stored in child_ids[0].
 * @see create_child()
 */
static vector<int>* child_ids;

/**
 * input string is written into @ref watchdog_output. same line is also written into console with @ref WATCHDOG_PREFIX.
 * @param line string that is written into @ref watchdog_output
 * @see WATCHDOG_PREFIX
 */
void writefile_watchdog(string line){
	fstream file;
	file.open(watchdog_output, fstream::app);
	if(file.is_open()){
		file << line << endl;
		cout << WATCHDOG_PREFIX << line << endl;
	}
	file.close();
}

/**
 * creates a child process and stores the @ref pid in related position in @ref child_ids
 * @param P_no id of the child that will be created
 * @return pid_t pid of the child that is created 
 * @see writefile_watchdog()
 */
pid_t create_child(int P_no){
	pid_t pid = fork();
	if(pid==0){// if child
		execlp("./process", "./process", to_string(P_no).c_str(), process_output.c_str(), NULL);
	}
	else if(pid > 0){// if parent
		child_ids->at(P_no-1) = pid;
		writefile_watchdog("P" + to_string(P_no) + " is started and it has a pid of " + to_string(pid));
	}
	else if(pid < 0){
		cout << WATCHDOG_PREFIX << "fork failed at " << P_no << endl;
	}
	// the final else is needed because c++ stuff
	// i swear i saw "how" once
	else cout << WATCHDOG_PREFIX << "how" << endl;
	return pid;
}

/**
 * unless killed by @ref SIGNAL_KILLSELF, a child will send @ref SIGNAL_CHILD_DEATH to watchdog.
 * This signal is handled by this function.
 * - if id is 1 which means process is head, all processes are killed using @ref SIGNAL_KILLSELF, in order to be restarted one by one via @ref create_child().
 * - else, the process is restarted via @ref create_child().
 * @param signo always @ref SIGNAL_CHILD_DEATH
 * @param info returns information about the signal, ie pid of child process
 * @see child_ids
 * @see create_child()
 * @see writefile_watchdog()
 */
static void handle_dying_child(int signo, siginfo_t* info, void*){
	int child_pid = info->si_pid;
	int id;
	for (int i = 0; i<child_ids->size(); i++){
		if((*child_ids)[i] == child_pid){
			id = i+1;
			break;
		}
	}
	if(id == 1){
		writefile_watchdog("P1 is killed, all processes must be killed");
		for(int i=1; i<child_ids->size(); i++){
			kill((*child_ids)[i], SIGNAL_KILLSELF);
			usleep(100000);
		}
		usleep(100000);
		writefile_watchdog("Restarting all processes");
		for (int P_no = 1; P_no <= num_of_process; P_no++){
			create_child(P_no);
			usleep(100000);
		}
		
	}
	else{
		writefile_watchdog("P" + to_string(id) + " is killed");
		writefile_watchdog("Restarting P" + to_string(id));
		create_child(id);
	}
}

/**
 * overrides SIGINT, sends @ref SIGNAL_KILLSELF to all children
 * @param signo always SIGINT, 2
 * @see child_ids
 */
static void terminate(int signo){
	cout << " SIGINT detected, terminating" << endl;
	for(int child_id: *child_ids){
		if (child_id == 0) continue;
		kill(child_id, SIGNAL_KILLSELF);
	}
	exit(0);
}

/**
 * main function does such in order:
 * 	- validates args and fills related variables @ref num_of_process, @ref instruction_path, @ref process_output and @ref watchdog_output.
 * 	- overrides SIGINT with @ref terminate()
 * 	- removes any old output files: @ref process_output and @ref watchdog_output
 * 	- creates signal handler that connects @ref SIGNAL_CHILD_DEATH signal into @ref handle_dying_child()
 * 	- creates @ref num_of_process amount of process'
 * 	- reads inputs from @ref instruction_path with a small delay
 * 	- terminates any remaining children process' with a small delay
 */
int main(int argc, char* argv[]){
	try{
		num_of_process = atoi(argv[1]);
		instruction_path = argv[2];
		process_output = argv[3];
		watchdog_output = argv[4];
	}
	catch(exception e){
		cout << WATCHDOG_PREFIX << "bad arg input" << endl;
		return 1;
	}

	child_ids = new vector<int>(num_of_process);
	signal(SIGINT, terminate);

	remove(process_output.c_str());
	remove(watchdog_output.c_str());

	//if any child process dies, it will send SIGNAL_CHILD_DEATH signal, below will handle such case
	memset(&mysignal, 0, sizeof (mysignal));
	mysignal.sa_sigaction = handle_dying_child;
	mysignal.sa_flags = SA_SIGINFO;
	sigaction(SIGNAL_CHILD_DEATH, &mysignal, NULL);

	//create children
	for (int P_no = 1; P_no <= num_of_process; P_no++){
		create_child(P_no);
	}
	
	/*
	cout << "current children pids:";
	for(int child_id : *child_ids){
		cout << " " << child_id;
	}
	cout << endl;

	cout << "----action----" << endl;
	*/

	// Start reading file, sending signals:
	fstream file;
	string line;
	file.open(instruction_path);

	map<string, int> SIGNAL_MAP = {
		{"SIGHUP",SIGHUP},
		{"SIGINT",SIGINT},
		{"SIGILL",SIGILL},
		{"SIGTRAP",SIGTRAP},
		{"SIGFPE",SIGFPE},
		{"SIGBUS",SIGBUS},
		{"SIGSEGV",SIGSEGV},
		{"SIGTERM",SIGTERM},
		{"SIGXCPU",SIGXCPU}
	};

	for(;getline(file, line, '\n');) {
		usleep(100000); //sleep for 100ms
		vector<string> token(2);
		stringstream sline(line);
		sline >> token[0] >> token[1];
		if(token[0] == "wait"){
			//sleep for token[1] seconds
			sleep(atoi(token[1].c_str()));
		}
		else{
			//send given signal to given process
			int id = atoi(token[1].substr(1).c_str());
			//cout << WATCHDOG_PREFIX << "Sending signal " << token[0] << "(" << SIGNAL_MAP[token[0]] << ") to P" << id << " (pid " << to_string((*child_ids)[id-1]) << ")" <<endl;
			kill((*child_ids)[id-1], SIGNAL_MAP[token[0]]);
		}
	}
	
	writefile_watchdog("Watchdog is terminating gracefully");
	// Kill any remaining children
	for(int child_id: *child_ids){
		if (child_id == 0) continue;
		kill(child_id, SIGNAL_KILLSELF);
		usleep(10000);
	}
	return 0;
}