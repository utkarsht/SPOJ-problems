#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
vector<ii> v;
ii overlap(ii a,ii b)
{
	if(b.first > a.second)
		return ii(-1,-1);
	if(b.second <= a.second)
		return b;
	else
		return ii(b.first,a.second);
}
int main()
{
	cin.sync_with_stdio(0);
	cout.sync_with_stdio(0);
	int t,a,b,n,bomb;
	ii ovrange,k;
	cin>>t;
	while(t--)
	{
		cin>>n;		bomb = 0;
		for(int i=0;i<n;i++)
		{
			cin>>a>>b;
			v.push_back(ii(a,b));
		}
		v.push_back(ii(2100,2100));
		n++;
		sort(v.begin(),v.end());
		int i = 0;
		for(int i=0;i<n;i++)
		{
			if(i!=0)	k = overlap(ovrange,v[i]);
			else		k = v[i];
			//cout<<k.first<<"  "<<k.second<<endl;
			if(k.first != -1)
			{
				ovrange = k;
			}
			else
			{
				ovrange = v[i];
				bomb++;
			}
		}
	//	if(bomb!=1)		bomb--;
		cout<<bomb<<endl;
		v.clear();
	}
}
