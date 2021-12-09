#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	start:
	system("color 90");
	//Initialization
	int temp,i,j,limit,position;
	float average_wait_time, average_t_time,sum=0.0;
	int burst_time[20],arival_time[20],process[20], waiting_time[20],turnaround_time[20],ct[20];
	
	cout<<"*******SJF Scheduling Algorithm (NON-Preemptive)*******\n\n";
	cout<<"\nEnter Total Number of Processes = ";
	cin>>limit;

	if(limit<=0)
 	{
 		system("color 47");
 		cout<<"Invalid Process Count . . .\n";
 		system("PAUSE");
 		system("CLS");
 		goto start;
	}
	else
	{
		system("CLS");
		system("color 27");
		for(i=0; i<limit; i++)
		{
			cout<<"Enter Burst Time For "<<i+1<<" = ";
			cin>>burst_time[i];
			process[i] = i+1;
		}
		for(int i=0; i<limit; i++)
		{
			position = i;
			for(j=i+1;j<limit;j++)
			{
				if(burst_time[j]<burst_time[position])
				{
					position=j;
				}
			}
		//swap 1
		temp= burst_time[i];
		burst_time[i]=burst_time[position];
		burst_time[position] = temp;
		//swap 2
		temp = process[i];
		process[i] = process[position];
		process[position]=temp;
		}
		//first w8ing time is always 0
		waiting_time[0] = 0;
		//calculate waiting time
		for(i=1; i<limit; i++)
		{
			waiting_time[i]=0;
			for(j=0; j<i; j++)
			{
				waiting_time[i] = waiting_time[i] + burst_time[j];
			}
			sum = sum + waiting_time[i];
		}
		average_wait_time = sum/limit;
		sum = 0;
		cout<<"\nProcess    Arival Time    Burst Time    Completion Time    Turnaround Time    Waiting Time";
		for(i=0; i<limit; i++)
		{
			arival_time[i]=0;
			ct[i]=0;
	    	for(j=0; j<i+1; j++)
	    	{
	    		ct[i]+=burst_time[j];
	    	}
			turnaround_time[i] = burst_time[i] + waiting_time[i]; //calculate TAT
			sum = sum + turnaround_time[i];
			cout<<"\nP["<<process[i]<<"]"<<"          "
				<<arival_time[i]<<"             "
				<<burst_time[i]<<"                   "
				<<ct[i]<<"                 "
				<<turnaround_time[i]<<"                 "<<waiting_time[i]<<endl;
		}
		average_t_time = sum/limit;
		cout<<"\nAverage Waiting Time    = "<<fixed << setprecision(2)<<average_wait_time<<endl;
		cout<<"\nAverage Turnarount Time = "<<average_t_time<<endl;
		cout<<"\nCPU Utilization : 100%\n";
		system("PAUSE");
	 	system("CLS");
	 	goto start;
	}
	return 0;
}
