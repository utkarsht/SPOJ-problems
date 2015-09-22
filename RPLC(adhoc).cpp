#include<iostream>
using namespace std;
int main()
{
	long long p,i,j,t,sum=0,ans,n,preans;
	cin>>t;
	for(p=1;p<=t;p++)
	{
		sum=0;
		ans=1;
		preans=0;
		cin>>n;
		int a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
			sum+=a[i];
			if(sum<=0)
			{
				ans=-sum+1;
				if(ans>preans)
				preans=ans;
			}
		}
		cout<<"Scenario #"<<p<<": "<<((ans>preans)?ans:preans)<<endl;
	}
}
