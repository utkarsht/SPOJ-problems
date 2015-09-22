
#include<list>
#include<stdio.h>
#include<queue>
using namespace std;
enum color{gray,black,white};
int count=1;
class vertex
{
	public:
	list<int> adjl;
	public:
	color c;
	void addedge(int d)
	{  adjl.push_back(d);  }
	vertex()
	{
		c=white;
	}
};
class Graph
{
	public:	
	vertex* v;
	Graph(int n) 
    {   v=new vertex[n];  }       
	void inputgraph(int e)
	{
		int a,b;
    	for(int i=0;i<e;i++)
	    {
		 scanf("%d %d",&a,&b);
		 a--;	b--;
		 v[a].addedge(b);
		 v[b].addedge(a);                             
	    }
	}
    bool bipartite(int k)
    {
    	queue<int> q;	int t;
    	q.push(k);									
    	v[k].c=black;
    	while(!q.empty())
    	{
    		t=q.front();
	        q.pop();      
	        list<int>:: iterator p=v[t].adjl.begin();
	    	while(p!=v[t].adjl.end())
	    	{
			if(v[*p].c==white)
			{  if(v[t].c==black) v[*p].c=gray;  else v[*p].c=black;   q.push(*p);   }
			else if(v[*p].c==v[t].c)		return false;
		    p++;
	    	}
    	}
    	return true;
	}
};
int main()
{
	int t,vt,e,k,i,j;
	scanf("%d",&t);
	for(j=1;j<=t;j++)
	{
		scanf("%d %d",&vt,&e);
		Graph g(vt);
		g.inputgraph(e);
		for(i=0;i<vt;i++)
		{
			if(g.v[i].c==white)
			{
				if(g.bipartite(i)==0)
				break;
			}
		}		
		printf("Scenario #%d:\n",j);
		if(i==vt)
			printf("No suspicious bugs found!\n");
		else
			printf("Suspicious bugs found!\n");
	}
}
