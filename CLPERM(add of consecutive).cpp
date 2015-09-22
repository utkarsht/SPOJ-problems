#include<bits/stdc++.h>
#define M 100005
using namespace std;
typedef unsigned long long ll; 
int main()
{
	cin.sync_with_stdio(0);
	cout.sync_with_stdio(0);
	int t,i,k,n,num;
	ll add,m,missum,tillsum;
	int miss[M];
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		if(k==0)
		{
			add = (n*(n+1))/2;
			add++;
			if(add%2 == 0)
				cout<<"Mom\n";	
			else
				cout<<"Chef\n";
			continue;
		}
		for(i=0;i<k;i++)
		{
			cin>>miss[i];
		}
		sort(miss,miss+k);
		if(miss[0] == 1)
		{	cout<<"Chef\n";		continue;	}
		if(miss[0] == 2)
		{	cout<<"Mom\n";		continue;	}
	
		missum = tillsum = 0;
		for(i=0;i<k;i++)
		{
			m = miss[i];
			tillsum = ((m-1)*(m))/2 - missum;
			missum += miss[i];
			if(miss[i]>tillsum)
			{
				cout<<((miss[i]&1)?"Chef":"Mom")<<endl;
				break;
			}
		//	cout<<i<<"  :    "<<missum<<"   "<<tillsum<<endl;
		}
		if(i==k)
			cout<<((((n*(n+1))/2 - missum + 1)&1) ? "Chef": "Mom")<<endl;
	}
}
