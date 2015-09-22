#include<iostream>
#include<string.h>
#include<cstdio>
#define M 1000000007
using namespace std;
long gcd(long a,long b)
{
	if(b==0)
	return a;
	else
	return gcd(b,a%b);
}
long L(long a, long b)
{
	if(a==b) return a;
	else
	{
		return (a/gcd(a,b))*b;
	}
}
int main()
{
	long pos,r,lcm;
	int n,k,t;
	char s[100000];
	scanf("%d",&t);
	while(t--)
	{
		lcm=1;
		k=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{ cin>>s[i]; }
		long a[100001]={0};
		bool v[100001]={0};
		for(int i=1;i<=n;i++)
		{
			r=pos=i;
			if(v[pos]==0)
			{
			pos=(int)s[pos-1]-'0';  a[k]++;
			v[pos]=1;
			while(pos!=r)
			{
				a[k]++;
				pos=(int)s[pos-1]-'0';
				v[pos]=1;
			}
			k++;
		    }
		}
		for(int i=0;i<k;i++)
		{
		    lcm=L(lcm,a[i])%M;
		}
		printf("%ld\n",lcm%M);
	}
}  
