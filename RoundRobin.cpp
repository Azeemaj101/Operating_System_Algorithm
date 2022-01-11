#include <iostream>
using namespace std; 
int main(){
	int n = 4,i; // number of processes
	int timeSlice = 5;
	int tSlice[4];
	int bTime[4];
	bTime[0] = 10;
	bTime[1] = 4 ;
	bTime[2] = 6 ;
	bTime[3] = 8 ;
	
	for (i=0; i<n; i++)
	{
		if (bTime[i]<timeSlice||bTime[i]==0)
		{
			tSlice[i]=bTime[i];
		}
	
		else
		{
			tSlice[i]=timeSlice;
		}
	}
	
	int flag;
	cout<<"Gantt chart for given processes and burst times:\n\n";
	do{
		flag=0;
		for (i=0; i<n; i++)
		{
			for (int j=0; j<tSlice[i]; j++)
			{
				cout<<"P"<<i<<"  ";
				bTime[i]--;
			}
			tSlice[i] = bTime[i];
			cout<<"\n";
		}
		for (i=0; i<n; i++)
		{
			if (bTime[i] != 0)
			{
				flag=1;
			}
		}
	}while (flag != 0);
}
