#include<iostream>
#include<list>
#include<queue>
#include<vector>
using namespace std;
class Disjset
{
	private:
		vector<int> s;
	public:
	Disjset(int num)
	{
		for(int i=0;i<num;i++)
	    s.push_back(-1);
	}
	int find(int x)
	{
		if(s[x]<0)
		return x;
		else
		return s[x]=find (s[x]);
	}
	void dounion( int root1,int root2)
	{
		if(s[root1]>=s[root2])
		{
			s[root2]+=s[root1];
			s[root1]=root2;
		}
		else
		{
			s[root1]+=s[root2];
			s[root2]=root1;
		}
	}
	void show()
	{
		int num=s.size();
		for(int i=0;i<num;i++)
	    cout<<i<<"-> "<<s[i]<<endl;
	}
};
class edge
{
	public:
		int a;
		int wt;
	    int b;
	    edge()
	    {	
	    }
	    edge(int a,int b,int wt)
	    {  this->a=a;    this->b=b;    this->wt=wt;     }
};
	bool operator<(edge const &p1,edge const &p2)
	{
		return p1.wt>=p2.wt;
	}
int main()
{
	int p,e,n,i,j;
	int t;
	string str;
	cin>>t;
	while(t--)
	{
		cin>>n;
		Disjset ds(n);
		priority_queue<edge> q;
		int a,b,weight;
		for(i=0;i<n;i++)
		{
			a=i;
			cin>>str>>e;
			for(j=0;j<e;j++)		{	cin>>b>>weight;		b--;	edge pre(a,b,weight);		q.push(pre);	}
		}
		int price=0,count=0;
       	while(!q.empty())
       	{
       		if(count==n)  break;
       		edge pre=q.top();    q.pop();
       		pre.a=ds.find(pre.a);   pre.b=ds.find(pre.b);
    		if(pre.a==pre.b)  
    		;
    		else
    		{
    		ds.dounion(pre.a,pre.b);
    		price+=pre.wt;
    		count++;
    	    }
       }
		cout<<price<<endl;        
	}
}
