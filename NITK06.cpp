#include<stdio.h>
#include<string.h>
#include<math.h>
#define s(x) scanf("%d",&x)
#define p(x) printf("%d",x)
#define sl(x) scanf("%lld",&x)
#define pl(x) printf("%lld",x)
#define gap	printf(" ")
#define nl   printf("\n")
#define chk   printf("hello    ")
#define F(x)	for(int i=0;i<x;i++)
#define all(c) (c).begin(),(c).end()
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
typedef long long ll;
typedef unsigned long long ull;

/*
#include<iostream>
#include<set>
#include<map>
#include<list>
#include<vector>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;
*/
//void print(int *a,int n)
//{	nl;	F(n)	{	p(a[i]);	space;	}	nl;		}

/*
#include<time.h>
#define timestart int tstart = clock()
#define printtime (double)(clock()-tstart)/CLOCKS_PER_SEC
*/
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
int main()
{
	int t,n;
	s(t);
	while(t--)
	{
		bool flag=1;
		s(n);
		int a[n];
		for(int i=0;i<n;i++)
		s(a[i]);
		for(int i=1;i<n;i++)
		{
			a[i] = a[i] - a[i-1];
			if(a[i]<0)	{	printf("NO\n");		flag=0;	break;		}
		}
		if(flag)
		{
			if(a[n-1]==0)	{	printf("YES\n");	}
			else			{	printf("NO\n");		}
		}
	}

}
