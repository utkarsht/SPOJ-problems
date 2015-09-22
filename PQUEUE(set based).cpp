#include<iostream>
#include<vector>
#include<set>
#include<queue>
#include<functional>
using namespace std;
struct node
{
	int data;
	int pos;
	node(int d,int p)
	{	data=d;	pos=p;	}
	node()
	{	}
};
int main()
{
	int t,m,n,a,i,j,k;
	cin>>t;
	node temp;
	while(t--)
	{
		cin>>n>>m;
		if(!n && !m)	break;
		int count=0;
		multiset<int,greater<int> > st;
		vector<node> v;
		for(i=0;i<n;i++)
		{
			cin>>a;		v.push_back(node(a,i));		if(i)	st.insert(a);
		}
		i=0;
		while(1)
		{
			if(v[i].data >= *st.begin() )
			{
				if(v[i].pos==m)		{		cout<<count+1<<endl;		break;		}
				else	{	v.erase(v.begin());		k=st.erase(v[0].data);	for(j=1;j<k;j++)	st.insert(v[0].data);		count++;		}
			}
			else
			{
				temp = v[0];
				v.push_back(v[0]);
				v.erase(v.begin());		k=st.erase(v[0].data);	for(j=1;j<k;j++)	st.insert(v[0].data);
				st.insert(temp.data);
			}
		}
	}
}
