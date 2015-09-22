#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector>
#include<stdio.h>
#define s(x) scanf("%d",&x)
#define p(x) printf("%d",x)
#define pl(x) printf("%lld",x)
#define nl   printf("\n")
typedef long long ll;
using namespace std;
int main()
{
	int i,n,t,place;
	string str;
	ll sum;
	s(t);
	while(t--)
	{
		sum=0;
		vector<int> vk,vb;
		s(n);
		for(i=1;i<=n;i++)
		{
			cin>>str;	s(place);
			if(i!=place)
			{	vb.push_back(place);	vk.push_back(i);	}
			
		}
		sort(vk.begin(),vk.end());
		sort(vb.begin(),vb.end());
		for(i=0;i<vk.size();i++)
		{
			sum+=abs(vk[i]-vb[i]);
		}
		pl(sum);	nl;
	}
}
