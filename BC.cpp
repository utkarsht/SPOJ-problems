#include<iostream>
#include<math.h>
#include<stdio.h>
#define L(x)	log2(x)
using namespace std;
int main()
{
	long long t,l,b,h;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>l>>b>>h;
		
		int k=(ceil(L(l))+ceil(L(b))+ceil(L(h)));
		long long m = (l*b*h-1);
		printf("Case #%d: %lld %d\n",i,m,k);
	//	cout<<"Case #"<<i<<": "<<m<<" "<<k<<endl;
	}
}
