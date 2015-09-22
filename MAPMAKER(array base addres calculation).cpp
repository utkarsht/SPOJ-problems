//   For formulae- http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=330

#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
int main()
{
	int t,q,d,base,byte,l,u,k,c0;	
	map<string,vector<int> >  mp;
	vector<ii> vp;
	vector<int> temp,a;
	string str;
	cin>>t>>q;
	while(t--)
	{
		cin>>str;	
		cin>>base>>byte>>d;
		for(int i=0;i<d;i++)
		{
			cin>>l>>u;
			vp.push_back(ii(l,u));
		}
		
		k = byte;	c0 = 0;
		for(int i=vp.size()-1;i>=0;i--)
		{
			temp.push_back(k);
			c0 += k*vp[i].first ; 
			k = k*(vp[i].second - vp[i].first + 1);
		}
		c0 = base - c0;	
		temp.push_back(c0);
		mp[str] = temp;
		temp.clear();
		vp.clear();
	}
	while(q--)
	{
		cin>>str;
		d = mp[str].size();	d--;
		for(int i=0;i<d;i++)
			cin>>k,
			a.push_back(k);
	
		int ans = 0;
		temp = mp[str];
		for(int i=0;i<temp.size()-1;i++)
		{
			ans += a[d-i-1]*temp[i];
		}
		ans += temp[temp.size()-1];
		cout<<str<<"[";
		for(int i=0;i<d-1;i++)
		{
			cout<<a[i]<<" ,";
		}
		cout<<a[d-1]<<"] = "<<ans<<endl;
	}
}
