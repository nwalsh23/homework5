#include <iostream>
using namespace std;

int main()
{
	int pid = fork();
	if (pid==0) {
	cout << "This is the child process." <<endl;
	}
	else {
	cout << "This is the parent process.";
	}
	return 0;
}

