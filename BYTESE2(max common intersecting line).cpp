#include<stdio.h>
#include<string.h>
#include<math.h>
#define s(x) scanf("%d",&x)
#define p(x) printf("%d",x)
#define sl(x) scanf("%lld",&x)
#define pl(x) printf("%lld",x)
#define nl   printf("\n")
#define gap   printf("    ")
#define F(x)	for(int i=0;i<x;i++)
#define all(c) (c).begin(),(c).end()
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
typedef long long ll;
typedef unsigned long long ull;


#include<iostream>
#include<set>
#include<map>
#include<list>
#include<vector>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;

struct pairs
{
	int x1;
	bool presence;
};

bool operator<(pairs const &p1,pairs const &p2)
{
	return p1.x1<p2.x1;
}
int main()
{
	int t,n,ans;
	s(t);
	int count;
	while(t--)
	{
		s(n);	pairs   p[2*n+1];	
		for(int i=0;i<2*n;i+=2)
		{	s(p[i].x1);		p[i].presence=true;		s(p[i+1].x1);		p[i+1].presence=false;	}
		sort(p,p+2*n);
		ans=0;
		count=0;
	//	F(2*n)	{	p(p[i].x1);		gap;	p(p[i].presence);	nl; }
		F(2*n)
		{
			if(p[i].presence==true)
				count++;
			else
				count--;
			ans = max(ans,count);
		}
		p(ans);	nl;
	}

}
