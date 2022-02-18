#include<iostream>
using namespace std;
int main()
{
	double tlb, x_mem, hit, miss, tEffective;
	cout<<"Calcluate effective memory access time\n";
	cout<<"Enter TLB\n";
	cin>>tlb;
	cout<<"Enter Memory\n";
	cin>>x_mem;
	cout<<"Enter Hit\n";
	cin>>hit;
	miss = 100 - hit;
	tEffective = ((hit/100)*(tlb+x_mem)) + ((miss/100)*(tlb+(2*x_mem)));
	cout<<"Effective time for memory access: "<<(float)tEffective;
}
