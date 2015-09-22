#include<bits/stdc++.h>
#define M 100
using namespace std;
typedef long long ll;
ll abs(ll a)
{
	return (a>0)?a:-a;
}
int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	ll a[M];	ll prefix[M];	ll max;
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>a[i];
		prefix[0] = a[0];
		for(int i=1;i<n;i++)
			prefix[i] = prefix[i-1] + a[i];
		for(int i=1;i<n-1;i++)
		{
			sum = sump()
		}
	}
}
