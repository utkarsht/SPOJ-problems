//   http://aphroditespartacus.wordpress.com/2011/05/24/spoj-8551-abcd/
//   the problem is based on the fact that we can break the whole 2*n column matrix into n parts of 2*2 matrix and individually check condition	O(n)

#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n,i,k,t,m;
	char d,pre,p,q;
	cin>>n;
	char str1[2*n];
	scanf("%s",str1);

	for(i=0;i<4;i++)
	{
		if(str1[0]==i+'A' || str1[1]==i+'A')
			;
		else
		{  	cout<<(char)(i+'A');	pre=i+'A';  	}
	}
	
	for(t=2;t<2*n;t+=2)
	{
		for(i=0;i<4;i++)
		{
			if(str1[t]==i+'A' || str1[t+1]==i+'A')
				;
			else
			{  	q=p;	p=i+'A';  	}
		}
		if(p==pre)
		{	cout<<q<<p;		pre=p;	}
		else
		{	cout<<p<<q;		pre=q;	}
	}
	cout<<endl;
}
