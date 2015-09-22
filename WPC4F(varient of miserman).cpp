#include<bits/stdc++.h>
using namespace std;
int min(int a,int b,int c)
{
	return min(a,min(b,c));
}
int main()
{
	int t,n;
	int a[22][3];
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>a[i][0]>>a[i][1]>>a[i][2];
		}
		for(int i=n-2;i>=0;i--)
		{
			a[i][2] += min(a[i+1][0],a[i+1][1]);
			a[i][1] += min(a[i+1][0],a[i+1][2]);
			a[i][0] += min(a[i+1][1],a[i+1][2]);
		}
	/*	for(int i=0;i<n;i++)
		{
			cout<<a[i][0]<<"  "<<a[i][1]<<"  "<<a[i][2]<<endl;
		}*/
		cout<<min(a[0][0],a[0][1],a[0][2])<<endl;
	}
}
