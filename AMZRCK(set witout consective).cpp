#include<bits/stdc++.h>
using namespace std;
#define M 50
typedef long long ll;
int n;
int main()
{
	int t,l,i,j;
	ll dp[M][M]	, p, ans;
	cin>>t;
	while(t--)
	{
		cin>>n;	ans=0;
	//	if(n<=2)	{	cout<<n<<endl;		continue;	}
		
		for(i=1;i<n-1;i++)
			dp[i][2] = n-i-1,
			ans+=dp[i][2];
			
		dp[n-1][2] = dp[n][2] = 0;
		for(l=3;l<=n/2;l++)
		{
			for(i=1;i<=n;i++)
			{
				p = 0;
				for(j=i+2;j<=n;j++)
				{
					p += dp[j][l-1];
				}
				dp[i][l] = p;
				ans += p;
			//	cout<<p<<endl;
			}
		}
	/*	for(l=1;l<=n;l++)
		{
			for(i=1;i<=n;i++)
				cout<<dp[i][l]<<" ";
			cout<<endl;
		}*/
		if(n>=5 && n%2==1)	ans++;
		cout<<(ans+n+1)<<endl;
	}
}
