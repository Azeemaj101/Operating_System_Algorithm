#include<stdio.h>
#include<unistd.h>
#include<iostream>
#include<stdlib.h>
#include<sys/types.h>
int main(){
int n,i;
std::cout<<"Enter number of processes :";
std::cin>>n;
int bTime[n];
int wTime[n];
int tATime[n];
for(i=0;i<n;i++){
std::cout<<"Enter burst time value:";
std::cin>>bTime[i];
}
int avgWTime =0;
int avgtATime=0;
wTime[0]=0;
for(i=1;i<n;i++){
wTime[i]=wTime[i-1]+bTime[i-1];
avgWTime=avgWTime+wTime[1];
}
for(i=0;i<n;i++){
tATime[i]=wTime[i]+bTime[i];
avgtATime=avgtATime+tATime[i];
}
avgWTime=avgWTime/n;
avgtATime=avgtATime/n;
for(i=0;i<n;i++){
printf("P%i:",i);
printf("Wait time %i\t",wTime[i]);
printf("Turnaround Time:%i\n",tATime[i]);
}
printf("\nAverage Wait time:%i\n",avgWTime);
printf("\nAverage Turnaround Time:%i\n\n",avgtATime);
return 0;
}
