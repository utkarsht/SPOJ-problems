//      template by Utkarsh trivedi
//      problem id-    FIBOSUM 
//	    Based on-  Recursion  of fib numbers  key point-- sum of n fib numbers is (n+2)th fib number
#include<stdio.h>
#include<math.h>
#define s(x) scanf("%d",&x)
#define p(x) printf("%d",x)
#define sl(x) scanf("%lld",&x)
#define pl(x) printf("%lld",x)
#define nl   printf("\n")
#define chk   printf("hello    ")
typedef long long ll;
typedef unsigned long long ull;
#define M 1000000007

#include<map>
using namespace std;

map<ll,ll> mp;
ll fib(ll x)
{
	if(mp.find(x)!=mp.end())  return mp[x];
	if(x%2==1)
	{
		mp[x]=(  ( fib((x-1)/2) * fib((x-1)/2) ) %M+ (fib((x+1)/2) * fib((x+1)/2))  % M ) % M;
	}
	else
	{
		mp[x]=((ll)2*fib(x/2)*fib((x/2) -1) % M + (fib(x/2) * fib(x/2))%M  ) % M;
	}
	return mp[x];
}
int main()
{
	int t;
	ll a,b,m,n,sum,c,i;
	s(t);
	mp[0]=0;	mp[1]=1;	mp[2]=1;	mp[3]=2;
	while(t--)
	{
		sl(m);	sl(n);	

		m--;
		a=fib(m+2);		b=fib(n+2);	  
		
	    sum=(b-a)%M;	
	    if(sum<0)    {	sum=sum+M;  sum=sum%M;  }
		pl(sum);
		nl;
	}

}
