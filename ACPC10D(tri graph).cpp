//      template by Utkarsh trivedi
//      problem id-                       Based on-
#include<stdio.h>
#include<string.h>
#define s(x) scanf("%d",&x)
#define p(x) printf("%d",x)
#define sl(x) scanf("%lld",&x)
#define pl(x) printf("%lld",x)
#define space	printf("    ")
#define nl   printf("\n")
#define chk   printf("hello    ")
#define F(x)	for(int i=0;i<x;i++)
#define MAX    100000
typedef long long ll;

ll min(ll x, ll y, ll z)
{
  return x < y ? (x < z ? x : z) : (y < z ? y : z);
}

ll min(ll a,ll b)
{
	return ( a > b ) ? b : a ;
}

ll min(ll a,ll b, ll c, ll d)
{
	return min(a,min(b,c,d));
}
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
	int n,i;
	for(int j=1;1;j++)
	{
		ll sum=0;
		s(n);	if(n==0)	break;
		ll a[n],b[n],c[n];
		//sum
		for(i=0;i<n;i++)
		{
			sl(a[i]);	sl(b[i]);	sl(c[i]);
		}
		c[n-1]=MAX;		a[n-1]+=b[n-1];
		for(i=n-2;i>=0;i--)
		{
			c[i]+=min(c[i+1],b[i+1]);
			b[i]+=min(c[i],a[i+1],b[i+1],c[i+1]);
			a[i]+=min(b[i],a[i+1],b[i+1]);
		}
	/*	for(i=0;i<n;i++)
		{
			pl(a[i]);space;		pl(b[i]);space; 	pl(c[i]);	nl;
		}*/
		printf("%d. %lld\n",j,b[0]);
	}
	
}
