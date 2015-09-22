#include<stdio.h>
#include<string.h>
#include<math.h>
#define s(x) scanf("%d",&x)
#define p(x) printf("%d",x)
#define sl(x) scanf("%lld",&x)
#define pl(x) printf("%lld",x)
#define nl   printf("\n")
#define chk   printf("hello    ")
#define F(x)	for(int i=0;i<x;i++)
typedef long long ll;
typedef unsigned long long ull;


/*
#define gc getchar_unlocked
void sfast(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}
*/
long double lagrange(int *fx,int n,int x)
{
	int i,j;
	long double mul,ans=0;
	for(i=0;i<n;i++)
	{	
		mul=fx[i];
		for(j=0;j<n;j++)
		{
			if(i!=j)	mul = (long double)(mul*(x-j-1))/(i-j);
		}
		ans+=mul;
	}
	return  ans;
}
int main()
{
	int t,n,c;
	double val;
	s(t);
	while(t--)
	{
		s(n);	s(c);
		int fx[n];
		F(n)	s(fx[i]);
		for(int i=1;i<=c;i++)
		{	val = lagrange(fx,n,n+i);		printf("%.0f",val);	printf(" ");	}
		nl;
	}

}
