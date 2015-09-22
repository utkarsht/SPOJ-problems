#include<iostream>
#include<list>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<queue>
using namespace std;
enum color{white,gray,black};
int maxi;
class vertex
{
	public:
	list<int> adjl;
	list<int>:: iterator p;
	public:
	bool visited;
	color c;
	int name,edgeto,arival,depart;
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
	Graph(int n) 
    {  numberofv=n;    v=new vertex[numberofv];  for(int i=0;i<n;i++) { v[i].name=i; v[i].visited=0;  v[i].c=white; } }        // create graph with given vertices
	void inputgraph(int* indegree,int n)
	{
		int a,b;
    	for(int i=0;i<n;i++)
	    {
		 cin>>a>>b;
		 a--;  b--;
		 v[a].addedge(b);
		 v[b].addedge(a);   
		 indegree[b]++;                          
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
	int Breadthfirstsearch(int n,int sz)
	{   
		int d[sz],k;
		for(int i=0;i<sz;i++) { v[i].c=white; }
		memset(&d,0,n*sizeof(int));
		bool flag=0;
	    queue<int> q;
	    q.push(n);
	    v[n].edgeto=-1;
	    d[n]=0;
	    int t;
	    while(!q.empty())
	    {
	    	t=q.front();
	        v[t].c=black;     q.pop();      
	        list<int>:: iterator p=v[t].adjl.begin();
	    	while(p!=v[t].adjl.end())
	    	{
			if(v[*p].c==white)
			{  v[*p].edgeto=t;     d[*p]=d[t]+1;  v[*p].c=gray;   q.push(*p);  }
		    p++;
	    	}
	    }
	    maxi=-1;
	    for(int i=0;i<sz;i++)
	    {
	    //	cout<<i<<"           "<<d[i]<<endl;
	    	if(maxi<d[i])
	    	{  maxi=d[i];  k=i; }
		}
		return k;
    }
};
int main()
{
	int n,k;
	cin>>n;
	Graph g(n);
	int indegree[n+1];
	memset(&indegree,0,n*sizeof(int));
	g.inputgraph(indegree,n-1);
//	g.showgraph();
//	cout<<bs<<endl;
	k=g.Breadthfirstsearch(1,n);
//	cout<<maxi<<endl;
	k=g.Breadthfirstsearch(k,n);
	cout<<maxi<<endl;
}
