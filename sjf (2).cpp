#include<stdio.h>
#include<iostream>

int main()
{
int temp,i,j,limit,sum=0,position;
float average_waiting_time,average_turnaround_time;
int burst_time[20],process[20],waiting_time[20],turnaround_time[20];
std::cout<<"Enter total number of processes:\t"<<std::endl;
std::cin>>limit;
for(i=0;i<limit;i++)
{
std::cout<<"Enter Burst time for process["<<i+1<<"]\t"<<std::endl;
std::cin>>burst_time[i];
process[i]=i+1;
}
for(i=0;i<limit;i++)
{
position=i;
for(j=i+1;j<limit;j++)
{
if(burst_time[j]<burst_time[position])
{
position=j;
}

}
temp=burst_time[i];
burst_time[i]=burst_time[position];
burst_time[position]=temp;
temp=process[i];
process[i]=process[position];
process[position]=temp;
}
waiting_time[0]=0;
for(i=1;i<limit;i++)
{
waiting_time[i]=0;
for(j=0;j<i;j++)
{
waiting_time[i]=waiting_time[i]+burst_time[j];
}
sum=sum+waiting_time[i];
}
average_waiting_time=sum/limit;
sum=0;
std::cout<<"Process Id\t\tBurst Time\t Waiting Time\t Turnaround Time\n"<<std::endl;
for(i=0;i<limit;i++)
{
turnaround_time[i]=burst_time[i] + waiting_time[i];
sum=sum + turnaround_time[i];
std::cout<<"Process["<<process[i]<<"]\t\t"<<burst_time[i]<<"\t\t"<<waiting_time[i]<<"\t\t"<<turnaround_time[i]<<std::endl;
}
average_turnaround_time=sum/limit;
std::cout<<"Average Waiting Time\t"<<average_waiting_time<<std::endl;
std::cout<<"Average Turnaround Time\t"<<average_turnaround_time<<std::endl;
return 0;
}
