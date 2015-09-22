#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
int main()
{
	int t;
	double p,s,b,v,b2;
	cin>>t;
    while(t--)
    {
    	cin>>p>>s;
    	p=(double)p/4;
    	s=(double)s/2;
    	//b2=(p+sqrt(p*p-3*s))/3.0;
    	b=(p-sqrt(p*p-3*s))/3.0;
    	v=b*b*(p-2*b);
    	printf("%.2f\n",v);
    }
}
