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
#define mset(x,val)	 memset(&x,val,sizeof(x))
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
struct vertex
{
	int out;
	int in;
};
int main()
{
	int n,c,total,reduced;
	vertex v[1002];
	for(int k=1;1;k++)
	{
		total = reduced = 0;	
		s(n);		if(n==0)	break;
		mset(v,0);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				s(c);		total += c;
				v[i].out += c;	v[j].in += c;	
			}
		}
		for(int i=0;i<n;i++)
		{
			if(v[i].in>v[i].out)	v[i].in-=v[i].out, 	v[i].out=0;
			else					v[i].out-=v[i].in,	v[i].in=0;
			reduced += v[i].out;
		}
		printf("%d. %d %d\n",k,total,reduced);
	}
}
