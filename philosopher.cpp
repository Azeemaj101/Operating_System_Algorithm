#include<iostream>
#include<pthread.h>
#include<stdlib.h>
#include<semaphore.h>
#include<unistd.h>
using namespace std;
sem_t chopstick[5];
void * philos(void *);
void eat(int);
int main()
{
	int n[5];
	pthread_t T[5];
	for(int i=0; i<5; i++)
	{
		sem_init(&chopstick[i],0,1);
	}
	for(int i=0; i<5; i++)
	{
		n[i]=i;
		pthread_create(&T[i],NULL,&philos,(void *)&n[i]);
	}
	for(int i=0; i<5; i++)
	{
		pthread_join(T[i],NULL);
	}	
}

void *philos(void *n)
{
	int ph=*(int *)n;
	cout<<"Philosopher "<<ph<<" wants to eat\n";
	cout<<"Philosopher "<<ph<<" tries to pick left chopstick\n";
	sem_wait(&chopstick[ph]);
	cout<<"Philosopher "<<ph<<" picks the left chopstick\n";
	sem_wait(&chopstick[(ph+1)%5]);
	cout<<"Philosopher "<<ph<<" picks the right chopstick\n";
	eat(ph);
	sleep(2);
	cout<<"Philosopher "<<ph<<" has finished eating\n";
	sem_post(&chopstick[(ph+1)%5]);
	cout<<"Philosopher "<<ph<<" leaves the right chopstick\n";
	sem_post(&chopstick[ph]);
	cout<<"Philosopher "<<ph<<" leaves the left chopstick\n";
}
void eat(int ph)
{
	cout<<"Philosopher "<<ph<<" begins to eat\n";
}

