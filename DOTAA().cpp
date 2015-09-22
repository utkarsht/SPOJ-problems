#include<iostream>
using namespace std;
int main()
{
	int t,n,m,d,k,i;
	cin>>t;
	while(t--)
	{
		k=0;
		cin>>n>>m>>d;
		int a[n];
		for(i=0;i<n;i++)
		cin>>a[i];
		for(i=0;i<m;i++)
		{
			a[k]-=d;
			if(a[k]<=0)  {  k++;   i--;  if(k>n-1)   {  cout<<"NO\n";   break;   }   }
		}
		if(i==m)  cout<<"YES\n";
	}
}
