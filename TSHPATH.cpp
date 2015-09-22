#include<iostream>
#include<stdio.h>
#include<list>
#include<string.h>
#include<map>
#include<queue>
#define s(x) scanf("%d",&x)
#define p(x) printf("%d",x)
#define MAX_INT 214748
using namespace std;
class edge
{
	public:
		int a;
		int wt;
	    int b;
	    edge()
	    {}
	    edge(int a,int b,int wt)
	    {    this->a=a;    this->b=b;    this->wt=wt;     }
};
	bool operator<(edge const &p1,edge const &p2)            // operator for priority queue
	{
		return p1.wt>=p2.wt;
	}
	
int i1[101],i2[101];
int p;
class vertex
{
	public:
	list<edge> adjl;
	public:
	bool visited;
	int pathlength;
	int name;
	void addedge(int d,int weight)
	{  
	  edge ob(name,d,weight);
	  adjl.push_back(ob); 
    }
};
class Graph
{
	private:
		int numberofv;
		vertex* v;
    public:
	Graph(int n)                        // create graph with given vertices
     { 
	  numberofv=n;    v=new vertex[numberofv]; 
	  for(int i=0;i<numberofv;i++)
		 {  v[i].name=i;     } 
     }        
	void inputgraph(int n)
	{
		int i,j,b,w,k;
		map<string,int>	m;
		char str[100],str1[100],str2[100];
		for(i=0;i<n;i++)
		{
			scanf("%s",str);		m[str]=i;
			s(k);
			for(j=0;j<k;j++)
			{
				s(b);	s(w);	b--;
				v[i].addedge(b,w);  
			    v[b].addedge(i,w);    
			}
		}
		s(p);
		for(i=0;i<p;i++)	
		{
			scanf("%s",str1);		scanf("%s",str2);
			i1[i]=m[str1];		i2[i]=m[str2];
		}
	}
    int SP(int save,int k)                   // source vertex is 0
    {
    	int count=0;
    	edge pre;
    	priority_queue<edge>  q;
    	v[k].pathlength=0;           
    	while(1)
    	{  
    	    if(count==numberofv)    break;
    		list<edge>:: iterator p;
    		p=v[k].adjl.begin();
    		v[k].visited=1;  count++;
    		while(p!=v[k].adjl.end())
    		{	
    			q.push(*p);
				p++;
    		}
    		while(!q.empty())
    		{
    			edge pre=q.top();    q.pop();
    			if(v[pre.b].visited==0)
			    {
			    	 if(v[(pre).b].pathlength>v[pre.a].pathlength+(pre).wt )
			    	 {
    			    	 v[(pre).b].pathlength=v[pre.a].pathlength+(pre).wt ;
    			     }
				     k=pre.b;   break;  
			     }
    		} 
    	}
    	return v[save].pathlength;
    }
    void reset()
    {
    	for(int i=0;i<numberofv;i++)
		 { v[i].visited=0;   v[i].pathlength=MAX_INT;   } 
    }
};
int main()
{
	int n,e;
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		Graph g(n);
		g.inputgraph(n);
		for(int i=0;i<p;i++)
		{
			g.reset();
			printf("%d\n",g.SP(i2[i],i1[i]));
		}
        
	}
}

