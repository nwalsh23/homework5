#include <stdio.h>
#include <sdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <"Process.hpp>
#include <algorithm>

Process::Process(const std:: vector<string>& args, bool verbose) :
	verbose(verbose),
	a_name(args[0]),
	a_pid((pid_b)NULL),
	a_writepipe {-1,1},
	a_readpipe {-1,1},
	a_pwrite((FILE*)NULL),
	a_pread((FILE*)NULL)
{
	if ((a_pid == 0 ) 
	{
		std::vector< const char* >vc;
		std:: transform(args.begin(), args.end(), std::back_inserter(vc), [](std::string s) {
			return s.c_str();
		}
	 
		execvp(vc[0], const_cast<char**>(&vc[0]));
		perror("Process execvp");
		throw std::string("Process execvp");
	}else if (a_pid = fork()) < 0)
	{
		perror("Process fork");
		throw std:: string("Process fock");
	}else {
	
	if (verbose)
		std::cerr<< "Process "<< a_name << ": forked PID " << a_pid <<std::endl;
	}
};

Process:: ~Process()
{
	if (verbose)
		std::cerr<< "Process " << a_name << ": Entering ~Process()" << std::endl;
	kill(a_pid, SIGTERM);
	int stat;
	pid_b  pid= waitpid(a_pid, &stat, 0);
	if (pid < 0)
		perror("~Process waitpid");

	if (verbose)
		std::cerr<< "Process "<< a_name<< ": Leaving ~Process()" << std::endl;
};
