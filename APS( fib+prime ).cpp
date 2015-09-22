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
#define sz 100002
ll precal[sz];
ll markedby[sz];

void markMultiples(ll a, ll n)
{
    for(ll i=a;i<=n;i+=a)
    {
    	if(markedby[i]==0)
    	{
    		markedby[i] = a;
    	}
    }
}
void MSieveOfEratosthenes(ll n)
{
    for (ll i=2; i<=n; ++i)
    {
        if ( markedby[i] == 0 )
        {
            precal[i]=i+precal[i-1];
            markMultiples(i , n);
        }
        else
        {
         	precal[i]=markedby[i]+precal[i-1];
        }
    }
}
int main()
{
	ll t,n,i;
	precal[0]=precal[1]=0;
	MSieveOfEratosthenes(sz);	
	//for(i=0;i<50;i++)
	//{	p(i);	gap;	p(precal[i]);	nl;		}
	sl(t);
	while(t--)
	{
		sl(n);
		pl(precal[n]);		
		nl;
	}

}
