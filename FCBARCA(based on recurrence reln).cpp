/*	In this question there are two types of person messi and other which are denoted by 0 and 1(respectively)
	then there is a recurence relation which is used below  
		From tutorial -- http://www.codechef.com/APRIL13/problems/FCBARCA/
*/
#include<bits/stdc++.h>
#define M 1000000007
#define sz 1003
using namespace std;
typedef long long ll;
int main()
{
	cin.sync_with_stdio(0);
	cout.sync_with_stdio(0);
	ll ans[sz][2];				//	ans[k][0] -- with messi		ans[k][1] -- without messi
	int t,k,n;		
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		ans[0][0] = 1;	ans[0][1] = 0;
		for(int i=1;i<=n;i++)
		{
			ans[i][0] = (ll)(k)*(ans[i-1][1])%(M) ;					// last position any one
			ans[i][1] = ( (ll)ans[i-1][0] + (ll)(k-1)*ans[i-1][1] ) % M ;	// last position messi and anyone excluding current person 
		}
		cout<<ans[n][0]<<endl;
	}
}
