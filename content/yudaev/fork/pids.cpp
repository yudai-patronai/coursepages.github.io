#include <unistd.h>

#include <iostream>

using namespace std;

int main()
{
	int a=0;   
	//cout << "My pid is " << getpid() << ", parent pid is " << getppid() << endl;
	fork();
	int pid=getpid();
	cout<<pid<< endl;
	int ppid=getppid();
	cout<<ppid<<endl;
    return 0;
}

