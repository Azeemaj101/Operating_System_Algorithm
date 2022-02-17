#include<iostream>
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
cout<<"Empty: "<<empty<<"Full: "<<full<<"Mutex: "<<mutex<<std::endl;
cout<<"Enter Your choice 1)Produce 2)Consume"<<std::endl;
int x;
cin>>x;
if(x==1)
{
if(empty!=0 && mutex==1)
{
cout<<"Enter the data"<<std::endl;
wait(empty);
wait(mutex);
cin>>a[full];
signal(mutex);
signal(full);
}
else
cout<<"Buffer is full"<<std::endl;
}
else if(x==2)
{
if(full>0 && mutex==1)
{
wait(full);
wait(mutex);
cout<<"Data is"<<a[full]<<std::endl;
signal(mutex);
signal(empty);
}
else
cout<<"Buffer is empty"<<std::endl;
}
else break;
}
return 0;
}
