#include<iostream>
using namespace std;
long gcd(long m ,long n)
{
	while(n!=0)	
	{
		long rem=m%n;
		m=n;
		n=rem;
	}
	return m;
}
int main()
{
	int t;
	long n,m,a,b,i,sum;
	cin>>t;
	while(t--)
	{
		a=1;    b=1;    sum=0;
		cin>>n>>m;
		a=1;b=1;
		for(i=1;i<2*n-1;i++)
		{
			sum=a+b;
			b=a;
			a=sum;
			b=b%m;
			a=a%m;
		}
		long k=gcd(b,a);
		b/=k;       a/=k;
		cout<<b%m<<"/"<<a%m<<endl;
	}
}
