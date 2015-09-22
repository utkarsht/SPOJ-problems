#include<stdio.h>
#include<stack>
#include<iostream>
#define s(x) scanf("%d",&x)
using namespace std;
int main()
{
	int t,n,p,k=1;
	stack<bool> a;
	s(t);
	while(t--)
	{
		p=0;
		k=1;
		s(n);
		if(n&1==1)
		cout<<n<<endl;
		else
		{
			a.push(0);
			while(n!=1)
			{
				a.push((n>>1)&1);
				n=n>>1;
			}
			while(!a.empty())
			{
				p+=a.top()*k;
				a.pop();  k=k<<1;
			}
			cout<<p<<endl;
	    }
	}
}
