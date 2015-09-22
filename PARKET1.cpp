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
	ll l,w,b,r;
	double l1,l2;
	double mid;
	sl(r);	sl(b);
	mid = ((r+4)/2)*((r+4)/2) - 4*(b+r);
	mid = sqrt(mid);
	l = ((r+4)/2)+mid;
	l /=2;
	pl(l);  gap;
	w = ((r+4)/2)-mid;
	w /=2;
	pl(w);	nl;
}
