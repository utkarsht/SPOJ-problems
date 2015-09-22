#include<iostream>
#include<list>
#include<queue>
using namespace std;
class edge
{
	public:
		int wt;
	    int b;
	    edge()
	    {
	    	
	    }
	    edge(int b,int wt)
	    {     this->b=b;    this->wt=wt;     }
};
	bool operator<(edge const &p1,edge const &p2)
	{
		return p1.wt>=p2.wt;
	}
class vertex
{
	public:
	list<edge> adjl;
	public:
	bool visited;
	void addedge(int d,int weight)
	{  
	  edge ob(d,weight);
	  adjl.push_back(ob); 
    }
};
class Graph
{
	private:
		int numberofv;
		vertex* v;
    public:
	Graph(int n) 
    {  numberofv=n;    v=new vertex[numberofv];  for(int i=0;i<n;i++) { v[i].visited=0;  } }        // create graph with given vertices
	void inputgraph(int e)
	{
		int a,b,weight;
	    for(int i=0;i<e;i++)
        {
		 cin>>a>>b>>weight;
		 a--;  b--;
		 v[a].addedge(b,weight);  
		 v[b].addedge(a,weight);                        
	    }
	}
    int PrimMST()
    {
    	int count=0,price=0,k=0;
    	edge pre;
    	priority_queue<edge>  q;
    	while(1)
    	{
    		if(count==numberofv)    return price;   
    		list<edge>:: iterator p;
    		p=v[k].adjl.begin();
    		v[k].visited=1;   count++;
    		while(p!=v[k].adjl.end())
    		{
				q.push(*p);
				p++;
    		}
    		while(!q.empty())
    		{
    			edge pre=q.top();    q.pop();
    			if(v[pre.b].visited==0) {     k=pre.b;    price+=pre.wt;   break;     }
    		} 
    	}
    }
};
int main()
{
	int n,p,e,mstwt;
	int t;
	cin>>t;
	while(t--)
	{
		cin>>p>>n>>e;
		Graph g(n);
		g.inputgraph(e);
        mstwt=g.PrimMST();
        cout<<p*mstwt<<endl;
	}
}
