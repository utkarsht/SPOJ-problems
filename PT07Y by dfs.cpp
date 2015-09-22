#include<iostream>
#include<list>
#include<stdlib.h>
#include<queue>
using namespace std;
int count=1;
int flag=0;
class vertex
{
	public:
	list<int> adjl;
	list<int>:: iterator p;
	public:
	bool visited;
	int name;
	void addedge(int d)
	{  adjl.push_back(d);  }
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
	Graph(int n) 
    {  numberofv=n;    v=new vertex[numberofv];  for(int i=0;i<n;i++) { v[i].name=i; v[i].visited=0;  } }        // create graph with given vertices
	void inputgraph(int m)
	{
		int a,b;
	    for(int i=0;i<m;i++)
	    {
		 cin>>a>>b;
		 a--;  b--;
		 v[a].addedge(b);
		 v[b].addedge(a);                             // for directed graph this will not be there.
	    }
	}
	void showgraph()
	{
		list<int>:: iterator p;
		for(int i=0;i<numberofv;i++)
    	{
		cout<<"Vertex "<<i<<" : ";
		v[i].adjacent();
		cout<<endl;
	    }
	}
	void DepthFirstSearch()
	{    DFS(v[0]);   }
	void DFS(vertex& vtx)
	{
		vtx.visited=1;
		count++;
		list<int>:: iterator p=vtx.adjl.begin();
		while(p!=vtx.adjl.end())
		{
			if(!v[*p].visited)
			{   DFS(v[*p]);   }
			else
			{
				if(*p==vtx.name) ;
				else
			flag=1;
		    }
			p++;
		}
	}
};
int main()
{
	int n,m;
	cin>>n>>m;
    Graph g(n);
    g.inputgraph(m);
    g.showgraph();
    g.DepthFirstSearch();
   if(flag==1  ||  count!=n-1)  cout<<flag<<"   "<<count<<"    "<<"NO\n";
   else  cout<<"YES\n";
}
