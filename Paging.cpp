#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int page,frame,memory,p,f,d;
	cout<<"Please Enter some Details \n";
	cout<<"Please Enter Total Pages in count\n";
	cin>>page;
	cout<<"Please Enter Total Frames in count\n";
	cin>>frame;
	cout<<"Please Enter Total Memory\n";
	cin>>memory;
	p=log2(page);
	f=log2(frame);
	d=log2(memory);
	cout<<"No. of bit need for Pages : "<<ceil(p)<<endl;
	cout<<"No. of bit need for Frames: "<<ceil(f)<<endl;
	cout<<"No. of bit need for Memory: "<<ceil(d)<<endl;
	cout<<"Logical  Address Size: "<<p+d<<endl;
	cout<<"Physical Address Size: "<<f+d<<endl;
}
