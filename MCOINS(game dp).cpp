#include<bits/stdc++.h>
using namespace std;
bool ans[1000002];
int ret(int i)
{
	if(i==0)
		return 0;
	if(i>0)
		return ans[i];
	else
		return 1;
}
int main()
{
	int k,l,m,n;
	cin>>k>>l>>m;
	ans[1] = 1;							// 1 for asen
	for(int i=0;i<m;i++)
	{
		cin>>n;
		for(int j=2;j<=n;j++)
		{
			ans[j] = (!ret(j-1) || !ret(j-k) || !ret(j-l));
			//cout<<j<<"  : "<<ans[j]<<endl;
		}
		if(ans[n]==1)	cout<<"A";
		else			cout<<"B";
	}
}
