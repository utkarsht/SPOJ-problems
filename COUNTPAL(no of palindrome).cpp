#include<bits/stdc++.h>
#define MAX 1003
#define M 1000000007
typedef long long ll;
using namespace std;
string str;
bool ispalin[MAX][MAX];
ll ans[MAX];
void precal_palin(int n)				// precalculating all palindrome between i and j in O(n^2)	time
{
	for(int i=0;i<n;i++)
	{
		// odd
		for(int l=i,h=i ; l>=0 && h<n ; l--,h++)
			if(str[l]==str[h]) ispalin[l][h] = true;
			else break;
		
		// even
		for(int l=i,h=i+1 ; l>=0 && h<n ; l--,h++)
			if(str[l]==str[h]) ispalin[l][h] = true;
			else break;
	}
}
void solve(int n)
{
	memset(&ans,0,sizeof(ans));
	ans[0] = 1;
//	for(int i=0;i<n;i++)
//		ans[i] = 1;
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			if(ispalin[i][j])
			{
				ans[j+1] = (ans[j+1] + ans[i])%M;
			}
		}
	}
/*	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cout<<ispalin[i][j]<<"  ";
		cout<<endl;
	}
	for(int i=0;i<=n;i++)
		cout<<ans[i]<<" " ;*/
	cout<<ans[n]<<endl;
}
int main()
{
	cin.sync_with_stdio(0);
	cout.sync_with_stdio(0);
	cin>>str;	int l = str.length();
	memset(&ispalin,0,sizeof(ispalin));
	precal_palin(l);
	solve(l);
}
