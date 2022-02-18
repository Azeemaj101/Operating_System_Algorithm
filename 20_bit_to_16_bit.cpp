#include<iostream>
using namespace std;
int main()
{
	int seg,off,phyAdd;
	cout<<"Enter 16-bit (HEXA) Segment Value\n";
	cin>>hex>>seg;
	cout<<"Enter value of 16-bit (HEXA) Offset\n";
	cin>>hex>>off;
	seg = seg*16;
	phyAdd= seg+off;
	cout<<"Physical Address is: "<<hex<<phyAdd<<"H\n";
}
