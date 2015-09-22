#include<bits/stdc++.h>
#define M 100005
using namespace std;
typedef long long ll;
ll pow(int base, int exponent, int modulus)
{
    ll result = 1;
    base = base%modulus;
    while (exponent > 0)
    {
        if (exponent%2 == 1)
           result = (ll)(result * base)% modulus;
        exponent = exponent >> 1;
        base = (ll)(base * base) % modulus;
    }
    return result;
}
int cum_freq[M][26];
int prime[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
ll solve(int l,int r,int m)
{
	ll ans = 1;		int p;
	for(int i=0;i<25;i++)
	{
		if(l>=0)  p = cum_freq[r][i]-cum_freq[l][i];
		else	  p = cum_freq[r][i];
	
		ans = (ans * pow(prime[i],p,m)) %m;
		//cout<<prime[i]<<" "<<cum_freq[l][i]<<endl;
	}
	return ans;
}
int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	int n,i,j,l,r,m,k,q;
	bool flag;
	int a[M];
	memset(&cum_freq,0,sizeof(cum_freq));
	cin>>n;
	for(i=0;i<n;i++)
		cin>>a[i];
	for(i=0;i<n;i++)
	{
		j = k = 0;
		flag = 0;
		while(a[i]>1)
		{
			while(a[i]%prime[j]==0)
			{	
				k++;
				a[i]/=prime[j];
				flag = 1;
			}
			if(flag)
			{
				flag = 0;	
				cum_freq[i][j] = k;
				k = 0;
			}
			j++;
		}
	}
	for(i=1;i<n;i++)
	for(j=0;j<25;j++)
	{
		cum_freq[i][j] += cum_freq[i-1][j]; 
	}
	/*for(int i=0;i<n;i++)
	{
		cout<<i+1<<" : ";
		for(int j=0;j<25;j++)
		{
			if(cum_freq[i][j]>0)
				cout<<cum_freq[i][j]<<"("<<j<<")  ";
		}
		cout<<endl;
	}*/
	cin>>q;
	while(q--)
	{
		cin>>l>>r>>m;	l--;	r--;
		cout<<solve(l-1,r,m)%m<<endl;
	}
}
