#include<iostream>
#include<list>
#include<stdlib.h>
#include<string.h>
#include<queue>
using namespace std;
int m,n;
bool ok(int x,bool b)
{
	if(x<0)  return 0;
	if(x>=m && b==1)  return 0;
	if(x>=n && b==0)  return 0;
	return 1;
}
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
	int name,edgeto;
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
    {  numberofv=n;    v=new vertex[numberofv];  for(int i=0;i<n;i++) { v[i].name=i;  v[i].c=white; } }
	void inputgraph()
	{
		int k=0,a,c,b,d;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
			    a=i+1;  c=j+1;  b=i-1;  d=j-1;
                if(ok(a,0))   v[k].addedge(k+m);
                if(ok(b,0))   v[k].addedge(k-m);
                if(ok(c,1))   v[k].addedge(k+1);
                if(ok(d,1))   v[k].addedge(k-1);
                k++;
			}
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
	void Breadthfirstsearch()
	{
	    queue<int> q;
	    int d[m*n];
	    memset(&d,0,m*n*sizeof(int));
	    int k=0;
	    char c;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
			cin>>c;
			if(c=='1')
			{    q.push(k);  d[k]=0;  v[k].c=gray;  }
            k++;
			}
		}
	    int t;
	    while(!q.empty())
	    {
	    	t=q.front();
	        v[t].c=black;     q.pop();
	        list<int>:: iterator p=v[t].adjl.begin();
	    	while(p!=v[t].adjl.end())
	    	{
			if(v[*p].c==white)
			{  d[*p]=d[t]+1;   v[*p].c=gray;   q.push(*p);   }
			p++;
	    	}
	    }
	    k=0;
	    for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
			cout<<d[k]<<" ";
            k++;
			}
			cout<<endl;
		}
    }
};
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	cin>>n>>m;
    Graph g(m*n);
    g.inputgraph();
  //  g.showgraph();
    g.Breadthfirstsearch();
    }
}
