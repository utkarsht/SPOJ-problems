#include<stdio.h>
#include<math.h>
#define s(x) scanf("%d",&x)
#define p(x) printf("%d",x)
#define sl(x) scanf("%lld",&x)
#define pl(x) printf("%lld",x)
#include<iostream>
typedef long long ll;

#include<map>
using namespace std;

ll M;

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
	int t,k;
	ll a,b,m,n,sum,c,i;
	s(t);
	while(t--)
	{
		cin>>n>>k;
		mp.clear();
		mp[0]=0;	mp[1]=1;	mp[2]=1;	mp[3]=2;
		M = pow(2,k);
		cout<<fib(n+1)<<endl;		// +1 because it starts from 1 2 
	}
}
