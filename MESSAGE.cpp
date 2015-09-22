#include<iostream>
#include<list>
#include<stdlib.h>
#include<queue>
#include<vector>
#include<utility>

using namespace std;
#define sz 10000
/*typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;*/

enum color{gray=0,black=1,white=2};
int count=1;
class vertex
{
	public:
	list<int> adjl;
	list<int>:: iterator p;
	public:
	bool visited;
	int distance;
	color c;
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
int wt[sz][sz];
class Graph
{
	private:
		int numberofv;
		vertex* v;
    public:
	Graph() {   }                                       // create empty graph
	Graph(int n) 										// create graph with given vertices
    {  
	   numberofv=n;    v=new vertex[numberofv];  
	   for(int i=0;i<n;i++) {   v[i].c=white; } 
	}        
	void inputgraph(int e)
	{
		int a,b,w;
		for(int i=0;i<e;i++)
		{
			cin>>a>>b>>w;
			a--;	b--;
			v[a].addedge(b);
			v[b].addedge(a);
			wt[a][b]=w;		wt[b][a]=w;
		}
	}
	void showgraph()								//   show the graph
	{
		list<int>:: iterator p;
		for(int i=0;i<numberofv;i++)
    	{
		cout<<"Vertex "<<i<<" : ";
		v[i].adjacent();
		cout<<endl;
	    }
	}
	void reset()
	{
		for(int i=0;i<numberofv;i++)
    	{		v[i].c=white; 	v[i].distance=0;  }
	}
	int Breadthfirstsearch(int st,int given)
	{   
	    queue<int> q;
	    q.push(st);
	    v[st].distance=0;
	    int t;
	    while(!q.empty())
	    {
	    	t=q.front();
	        v[t].c=black;    	if(t==given)		break; q.pop();      
	        list<int>:: iterator p=v[t].adjl.begin();
	    	while(p!=v[t].adjl.end())
	    	{
			if(v[*p].c==white)
			{   v[*p].distance=v[t].distance+ wt[t][*p];		v[*p].c=gray;   q.push(*p);   }
		    p++;
	    	}
	    }
	    return v[given].distance;
    }
   
};
int main()
{
	int n,choice,q,a,b,j,k;
	cin>>n;
    Graph g(n);
    g.inputgraph(n-1);
    //g.showgraph();
    cin>>q;
    for(int i=0;i<q;i++)
    {
    	cin>>a>>b;
    	g.reset();
    	
    	cout<<g.Breadthfirstsearch(a-1,b-1)<<endl;
    
    }
}
