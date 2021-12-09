#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	start:
	system("color 90");
    int bt[20],at[20],ct[20],p[20],wt[20],pos,tat[20],pr[20],n; //p=> process, pos=> position, n=> Total Processes
	float total=0,temp,avg_wt,avg_tat;
	cout<<"*******Priorit Scheduling Algorithm (NON-Preemptive)*******\n\n";
    cout<<"Enter Total Number of Process: ";
    cin>>n;
 	if(n<=0)
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
    cout<<"\nEnter Priority & Burst Time\n";
    for(int i=0;i<n;i++)
    {
        cout<<"\n\t\t\t*****Process["<<i+1<<"]*****\n";
        cout<<"Process Priority: ";
        cin>>pr[i];
		cout<<"Burst Time      : ";
        cin>>bt[i];
        p[i]=i+1;           //contains process number
    }
 
    //sorting burst time, priority and process number in ascending order using selection sort
    for(int i=0;i<n;i++)
    {
        pos=i;
        for(int j=i+1;j<n;j++)
        {
            if(pr[j]<pr[pos])
                pos=j;
        }
 		//swap 1
        temp=pr[i];
        pr[i]=pr[pos];
        pr[pos]=temp;
 		//swap 2
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
 		//swap 3
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
 
    wt[0]=0;            //waiting time for first process is zero
 
    //calculate waiting time
    for(int i=1;i<n;i++)
    {
        wt[i]=0;
        for(int j=0;j<i;j++)
            wt[i]+=bt[j];
 
        total+=wt[i];
    }
 
    avg_wt=total/n;      //average waiting time
    total=0;
    cout<<"\nProcess    Priority    Arival Time    Burst Time    Completion Time    Waiting Time    Turnaround Time";
    for(int i=0;i<n;i++)
    {
    	at[i]=0;
    	ct[i]=0;
    	for(int j=0; j<i+1; j++)
    	{
    		ct[i]+=bt[j];
    	}
		tat[i]=bt[i]+wt[i];     //calculate turnaround time
        total+=tat[i];
        cout<<"\nP["<<p[i]<<"]"<<"          "
			<<pr[i]<<"            "
			<<at[i]<<"             "
			<<bt[i]<<"                 "
			<<ct[i]<<"                 "
			<<wt[i]<<"                 "<<tat[i];
    }
 
    avg_tat=total/n;     //average turnaround time
    cout<<"\n\nAverage Waiting Time  = "<<fixed << setprecision(2)<<avg_wt;
    cout<<"\nAverage Turnaround Time = "<<avg_tat;
    cout<<"\nCPU Utilization : 100%\n";
    system("PAUSE");
 	system("CLS");
 	goto start;
	}
    return 0;
}
