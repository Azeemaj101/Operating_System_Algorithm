#include <iostream>
using namespace std;
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
	int a[5];
	int empty=5;
	int full=0;
	int mutex=1;
	while(1)
	{
	cout<<"-------------------------------"<<endl<<endl;
	
	cout<<"Empty = "<<empty<<" , Full = "<<full<<" , Mutex = "<<mutex<<endl;
	
	cout<<"Enter your choice 1)Produce 2)Consume"<<endl;
	int x;
	cin>>x;
	if(x==1){
		if(empty != 0 && mutex==1)
		{
			cout<<"Enter the data "<<endl;
			wait(empty);
			wait(mutex);
			cin>>a[full];
			signal(mutex);
			signal(full);
		}
	else
		cout<<"Buffer is full"<<endl;
	}
	
	else if(x==2){
		if(full>0 && mutex==1)
		{
			wait(full);
			wait(mutex);
			cout<<"Data is "<<a[full]<<endl;
			signal(mutex);
			signal(empty);
		}
		
		else
		cout<<"Buffer is empty"<<endl;
	}
	
	else 
		break;
	}
	return 0;
}
