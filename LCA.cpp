#include<iostream>
#include<list>
#include<stdlib.h>
#include<queue>
#include<vector>
using namespace std;
enum color{white,gray,black};
int count=1;
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
	void inputgraph(int n)
	{
		int a,b;
    	for(int i=1;i<=n-1;i++)
	    {
		 cin>>a>>b;
		 a--;   b--;
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
	void Breadthfirstsearch(int z)
	{   
	    queue<int> q;
	    q.push(z);
	    v[z].edgeto=-1;
	    int t;
	    while(!q.empty())
	    {
	    	t=q.front();
	        v[t].c=black;     q.pop();      
	        list<int>:: iterator p=v[t].adjl.begin();
	    	while(p!=v[t].adjl.end())
	    	{
			if(v[*p].c==white)
			{  v[*p].edgeto=v[t].name;   v[*p].c=gray;   q.push(*p);   }
		    p++;
	    	}
	    }
    }
    void bfstree(int r)
    {
    	int a;
	    for(int i=0;i<numberofv;i++)
	    {
	    	a=i;
	    	cout<<"i  "<<i<<"    ";
	    	while(1)
	    	{
	    		if(a==-1)  break;
    	        a=v[a].edgeto;  cout<<a<<"   ";
	    	}
	    	cout<<endl;
     	}
    }
    void makev(int r,int a)
    {
    	vector<int> ve;
    	while(1)
    	{
    	ve.push_back(a);
    	if(a==r)  break;
    	a=v[a].edgeto;
        }
        vector<int>:: iterator p=ve.begin();
		while(p!=ve.end())
		{   cout<<*p<<"   ";  p++;}
    }
};
int main()
{
	int n,r,a,b,q;
	cin>>n;
    Graph g(n);
    g.inputgraph(n);
    g.showgraph();
    cin>>q;
    for(int i=0;i<q;i++)
    {
    	cin>>r;
    	r--; // a--;   b--;
    	g.Breadthfirstsearch(r);
        g.bfstree(r);
        cout<<endl;
        //if(r!=a)  g.makev(r,a);  if(r!=b) g.makev(r,b);
    }
}
