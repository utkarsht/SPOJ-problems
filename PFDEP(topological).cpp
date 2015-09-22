#include<iostream>
#include<list>
#include<stdlib.h>
#include<algorithm>
#include<queue>
#include<set>
using namespace std;
class vertex
{
	public:
	list<int> adjl;
	list<int>:: iterator p;
	public:
	bool visited;
	int indegree;
	void addedge(int d)
	{  adjl.push_back(d);  }
	bool contains(int d)
	{
		p=adjl.begin();
		while(p!=adjl.end())
		{  if(*p==d) return 1;   p++;    }
		return 0;
	}
	void adjacent()
	{
		p=adjl.begin();
		while(p!=adjl.end())
		{
			cout<<*p<<" ";	p++;
		}
	}
};
class Graph
{
	private:
		int numberofv;
		vertex* v;
    public:
	Graph() {   }                                                        // create empty graph
	Graph(int n)                                                         // create graph with given vertices
    {  numberofv=n;    v=new vertex[numberofv]; 
	   for(int i=0;i<n;i++) { v[i].visited=0;  v[i].indegree=0; } 
	}       
	void inputgraph(int m)
	{
		int a,b,i;
		for(int j=0;j<m;j++)
		{
			cin>>b>>i;	b--;	v[b].indegree+=i;
			while(i--)
			{
				cin>>a;		a--;
				v[a].addedge(b); 
			}
		}		
	}
    void topological()                             // this one work only if name 0 is give to first vertex i.e. root vertex   indegee(0)=0
    {
    	set<int> st;
    	for(int i=0;i<numberofv;i++)
		{
			if(v[i].indegree==0)
			{	st.insert(i);	}
		}                                
		int k;
		while(!st.empty())
		{
			k=*st.begin();    st.erase(st.begin());
			cout<<(k+1)<<" ";
			list<int>:: iterator p=v[k].adjl.begin();
			while(p!=v[k].adjl.end())
	    	{
			if(--v[*p].indegree==0)
			{    	
				st.insert(*p);
		    }
			p++;
	    	} 
		}  
		cout<<endl;             
	}
};
int main()
{
	int n,m;
	cin>>n>>m;
	Graph g(n);
	g.inputgraph(m);
    g.topological();
}
