#include <iostream>
#include <fstream>
#include <signal.h>
#include <unistd.h>

using namespace std;


/**
 * user signal #1 that process sends to watchdog when it dies.
 * @see self_kill()
 */
#define SIGNAL_CHILD_DEATH 30

/**
 * user signal #2 that watchdog sends to process in order to shut it down. @n 
 * note that this signal is different from SIGTERM as process' that are sent this signal do not return @ref SIGNAL_CHILD_DEATH to watchdog.
 * @ref SIGNAL_CHILD_DEATH is sent to watchdog in order to be handled via @ref handle_dying_child()
 * @see  self_kill_hard()
 */
#define SIGNAL_KILLSELF 31

/**
 * id of the process, given as an argument
 */
static int id;

/**
 * path of the process' output, given as an argument
 * @see writefile_process()
 */
static string process_output;

/**
 * anything written into @ref process_output is also written onto console, with prefix "->"
 * @see writefile_process()
 */
static const string PROCESS_PREFIX = "-> ";

/**
 * input string is written into @ref process_output. same line is also written into console with @ref PROCESS_PREFIX.
 * @param line string that is written into @ref process_output
 * @see PROCESS_PREFIX
 */
void writefile_process(string line){
	fstream file;
	file.open(process_output, fstream::app);
	if(file.is_open()){
		file <<  line << endl;
		cout << PROCESS_PREFIX << line << endl;
	}
}

/**
 * sends @ref SIGNAL_CHILD_DEATH to watchdog, writes onto @ref process_output and kills the process. differs from @ref self_kill_hard() as it sends a signal to the watchdog to be restarted.
 * @param signo always @ref 15
 * @see  self_kill_hard()
 * @see handle_signal()
 * @see writefile_process()
 */
void self_kill(int signo){
	//cout << PROCESS_PREFIX << ("P" + to_string(id) + " (pid " + to_string(getpid()) + ") received signal " + to_string(signo)) << " - shutdown initiated" <<endl;
	writefile_process("P" + to_string(id) + " received signal 15, terminating gracefully");
	//usleep(id*1000);
	kill(getppid(), SIGNAL_CHILD_DEATH);
	exit(0);
}

/**
 * writes onto @ref process_output and kills the process. differs from @ref self_kill() as it does not send a signal to the watchdog to be restarted
 * @param signo always @ref SIGNAL_KILLSELF, 31
 * @see self_kill()
 * @see handle_signal()
 */
void  self_kill_hard(int signo){
	writefile_process("P" + to_string(id) + " received signal 15, terminating gracefully");
	exit(0);
}

/**
 * all other signals but @ref SIGNAL_KILLSELF and SIGTERM are handled by this function. writes onto @ref process_output.
 * 
 * @see writefile_process()
 * @see self_kill()
 * @see  self_kill_hard()
 */
void handle_signal(int signo){
	//cout << PROCESS_PREFIX << ("P" + to_string(id) + " (pid " + to_string(getpid()) + ") received signal " + to_string(signo)) << endl;
	writefile_process("P" + to_string(id) + " received signal " + to_string(signo == 7 ? 10 : signo));
}

/**
 * main function does such in order:
 * 	- fills args @ref id, @ref process_output via args
 * 	- creates signal handlers @ref self_kill, @ref  self_kill_hard and @ref handle_signal
 * 	- writes onto @ref process_output
 * 	- waits for signals
 * 	@see writefile_process()
 */
int main(int argc, char* argv[]){
	usleep(100000);
    id = atoi(argv[1]);
    process_output = argv[2];
	signal(SIGTERM, self_kill);
	signal(SIGHUP, handle_signal);
	signal(SIGINT, handle_signal);
	signal(SIGILL, handle_signal);
	signal(SIGTRAP, handle_signal);
	signal(SIGFPE, handle_signal);
	signal(SIGBUS, handle_signal);
	signal(SIGSEGV, handle_signal);
	signal(SIGXCPU, handle_signal);
	signal(SIGNAL_KILLSELF,  self_kill_hard);
	//cout << PROCESS_PREFIX << "P" + to_string(id)+ " is waiting for a signal" << endl;
    writefile_process("P" + to_string(id)+ " is waiting for a signal");
	//cout << "awaken: " << getpid() << endl;
	
	while (true) usleep(10000);
    return 0;
}