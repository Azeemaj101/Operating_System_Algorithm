#include <iostream>
#include <sys/types.h>
#include <unistd.h>
using namespace std;

int main() {
    pid_t childOne, childTwo;
	
    childOne = fork();
    childTwo = fork();

    if (childOne == 0) {
        cout << "Child one is zombie now! " << endl;
    } else if (childTwo == 0) {
        sleep(10);
        cout << endl << "Child two is orphan" << endl;
    } else {
        sleep(5);
        cout << "Parent is executing " << endl;
    }
}