//      template by Utkarsh trivedi
//      problem id-                       Based on-
#include<stdio.h>
#include<string.h>
#define s(x) scanf("%d",&x)
#define p(x) printf("%d",x)
#define sl(x) scanf("%lld",&x)
#define pl(x) printf("%lld",x)
#define space	printf("   ")
#define nl   printf("\n")
#define chk   printf("hello    ")
#define F(x)	for(int i=0;i<x;i++)
typedef long long ll;
typedef unsigned long long ull;

//#include<iostream>
#include<set>
#include<map>
#include<list>
#include<vector>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;

void print(int *a,int n)
{	nl;	F(n)	{	p(a[i]);	space;	}	nl;		}	
// for fast input include below one
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
	int n;
	while(1)
	{
		s(n);	if(!n)	break;	bool f=0;
		int a[n];
		F(n)	s(a[i]);
		sort(a,a+n);
		for(int i=1;i<n;i++)
		{
			if(a[i]-a[i-1]>200)
			{	f=1;	printf("IMPOSSIBLE");	break;	 }
		}
		if(!f)
		{
			if(1422-a[n-1]<=100)		printf("POSSIBLE");
			else						printf("IMPOSSIBLE");
		}
		nl;
	}

}
