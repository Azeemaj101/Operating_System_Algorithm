#include<iostream>
#include<pthread.h>
#include<stdlib.h>
#include<semaphore.h>
#include<unistd.h>
using namespace std;
sem_t wrt;
int mutex=1;
int readcount=0;
void * reader(void *);
void * writer(void *);

void wait(int &x)
{
	if(x>0)
		x--;
}

void signal(int &x)
{
	x++;
}

int main()
{
	system("color F4");
	string n[2]={"Reader","Writer"};
	pthread_t T[1];
	sem_init(&wrt,0,1);
	int input;
	while(true)
	{
		cout<<"\n\t\t\tCode => Readers Writers Problem \n";
		cout<<"\t\t\tBlock == 4 Second Delay\n";
		cout<<"Press 1 For Reader-Writer\n";
		cout<<"Press 2 For Writer-Reader\n";
		cout<<"Press 3 For Writer-Writer\n";
		cout<<"Press 4 For Reader-Reader\n";	
		cout<<"Press 5 for Exit\n";
		cin>>input;
		switch(input)
		{
			case 1:
				{
					system("CLS");
					cout<<"\t\t\tReader-Writer\n\n";
					cout<<"Reader Enter in the Critical Section first and Block Writer (4 seconds)\n";
					for(int i=0; i<1; i++)
					{
						pthread_create(&T[i],NULL,&reader,(void *)&n[0]);
						pthread_create(&T[i],NULL,&writer,(void *)&n[1]);
					}	
					for(int i=0; i<1; i++)
					{
						pthread_join(T[i],NULL);
					}
					system("PAUSE");
					system("CLS");
					break;
				}
			case 2:
				{
					system("CLS");
					cout<<"\t\t\tWriter-Reader\n\n";
					cout<<"Writer Enter in the Critical Section first and Block Reader (4 seconds)\n";
					for(int i=0; i<1; i++)
					{
						pthread_create(&T[i],NULL,&writer,(void *)&n[1]);
						pthread_create(&T[i],NULL,&reader,(void *)&n[0]);
					}
					for(int i=0; i<1; i++)
					{
						pthread_join(T[i],NULL);
					}
					system("PAUSE");
					system("CLS");
					break;
				}
			case 3:
				{
					system("CLS");
					cout<<"\t\t\tWriter-Writer\n\n";
					cout<<"Writer one Enter in the Critical Section but they can't allow a second writer to enter in CS (4 seconds)\n";
					for(int i=0; i<2; i++)
					{
						pthread_create(&T[i],NULL,&writer,(void *)&n[1]);
					}
					for(int i=0; i<2; i++)
					{
						pthread_join(T[i],NULL);
					}
					system("PAUSE");
					system("CLS");
					break;
				}
			case 4:
				{
					system("CLS");
					cout<<"\t\t\tReader-Reader\n\n";
					cout<<"Both Readers are entered in the Critical Section at the same time!\n";
					for(int i=0; i<2; i++)
					{
						pthread_create(&T[i],NULL,&reader,(void *)&n[0]);
					}
					for(int i=0; i<2; i++)
					{
						pthread_join(T[i],NULL);
					}
					system("PAUSE");
					system("CLS");
					break;
				}
			case 5:
				{
					exit(0);
				}
		}
	}
}

void *writer(void *n)
{
	string str=*(string *)n;
	sem_wait(&wrt);
		cout<<str<<" Enter\n";
		sleep(4);
	sem_post(&wrt);
}

void *reader(void *n)
{
	string str=*(string *)n;
	wait(mutex);
	readcount++;
	if(readcount == 1) {
		sem_wait(&wrt);
	}
	signal(mutex);
	cout<<str<<" Enter\n";
	sleep(4);
	wait(mutex);
	readcount--;
	if(readcount == 0) {
	sem_post(&wrt);
	}
	signal(mutex);
}

