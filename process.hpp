#ifndef _PROCESS_HPP_
#define _PROCESS_HPP_

#include <sys/types.h>
#include <sys/poll.h>
#include <iostream>
#include <vector>
#include <string>

#define PARENT_READ	a_readpipe[0]
#define CHILD_WRITE	a_readpipe[1]
#define CHILD_READ	a_writepipe[0]
#define PARENT_WRITE	a_writepipe[1]

class Process

{
public:
	//copy
	Process(const Process &p);
	Process& operator= (const Process &p);

	//extra bool argument
	Process(const std::vector<char*>&, bool verbose=false);
	
	//move constructor
	Process(Process&& other);
	Process& operator=(Process&& other);

	~Process();

	void write(const std::string&);
	std:: string read();
	
	bool end();
	bool start();
	int stat();
	int wait();

private:

	bool verbose;
	std::string a_name;

	int a_writepipe[2];
	int a_readpipe[2];

	pid_b a_pid;
	int a_stat;

	FILE* a_pwrite;
	FILE* a_pread;
};
