//      template by Utkarsh trivedi
//      problem id-                       Based on-
#include<stdio.h>
#include<string.h>
#define s(x) scanf("%d",&x)
#define p(x) printf("%d",x)
#define sl(x) scanf("%lld",&x)
#define pl(x) printf("%lld",x)
#define nl   printf("\n")
#define chk   printf("hello    ")
#define F(x)	for(int i=0;i<x;i++)
typedef long long ll;
typedef unsigned long long ull;

#define M 10000007
ll pw(ll a,	ll b)			//   function for a power b
{
	ll result = 1;
	a = a % M ;
	while(b>0)
	{
		if(b%2==1)
			result=(result*a) % M ;
		a= (a*a) % M ;
		b=b>>1;
	}
	return result;
}
int main()
{
	int t;
	ll n,k,a,b,c,d,ans;
	while(1)
	{
		sl(n);	sl(k);	if(!n && !k)  break;
		if(n==1)	{	printf("1\n");	continue;	}
		a=( 2 * pw(n-1 , n-1)) % M ;
		b=(pw(n,n) % M);
		c=(2* pw(n-1 , k) ) % M;
		d=( pw(n,k)) % M;
		ans = (a + b + c + d)% M;
		pl(ans);	nl;
	}
} 
