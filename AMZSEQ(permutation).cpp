#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	long long n,p,q,ans,k;
	cin>>n;
	if(n==1)	{	cout<<"3\n";	}
	else if(n==2)	{	cout<<"7\n";	}
	else
	{
		p=2;	q=1;
		for(int i=3;i<=n;i++)
		{
			k = q;
			q = q+p;
			p = p+2*k;
		//	cout<<p<<"   "<<q<<endl;
		}
		cout<<2*p+3*q<<endl;
	}
}
