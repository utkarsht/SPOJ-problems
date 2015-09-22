#include<bits/stdc++.h>
#define M 100002
using namespace std;
struct person
{
	int arr;
	int dep;
	person(int a,int b )
	{
		arr = a;		dep = b;
	}
};
bool cmp(person a,person b)
{
	if(a.dep==b.dep)
		return a.arr<b.arr;
	return a.dep<b.dep;
}
int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	int t,n,k;		int arr,dep,prefer;
	cin>>t;			int total,time,last;
	map<int,vector<person> > m;
	map<int,vector<person> >:: iterator p;
	while(t--)
	{
		cin>>n>>k;		total = 0;	
		for(int i=0;i<n;i++)
		{
			cin>>arr>>dep>>prefer;
			m[prefer].push_back(person(arr,dep));
		}
		p = m.begin();
		while(p!=m.end())
		{
			sort((p->second).begin(),(p->second).end(),cmp);
			p++;
		}
		p = m.begin();
		while(p!=m.end())
		{
			vector<person> & ret = p->second;
			total++;
			last = ret[0].dep;
			for(int i=1;i<ret.size();i++)
			{
				if(last<=ret[i].arr)
					total++,
					last = ret[i].dep;
			}
			p++;
		}
		cout<<total<<endl;
		m.clear();
	}
}
