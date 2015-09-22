//	same as longest path in tree   solvable by 2 bfs

#include<iostream>
#include<list>
#include<stdio.h>
#include<string.h>
#include<queue>
#define S 100					//	for programm it should be 1001

#define s(x) scanf("%d",&x)
#define p(x) printf("%d",x)
#define nl   printf("\n")

using namespace std;
enum color{white,gray,black};
int maxi;
int c[S][S];
class vertex
{
	public:
	list<int> adjl;
	public:
	color c;
	void addedge(int d)
	{  adjl.push_back(d);  }
};
class Graph
{
	private:
		int numberofv;
		vertex* v;
    public:
	Graph(int n) 
    {  numberofv=n;    v=new vertex[numberofv];  for(int i=0;i<n;i++) {  v[i].c=white; } }        // create graph with given vertices
	void inputgraph(int m,int n)
	{
		int  i,j,k=0,l;
		for(i=0;i<n-1;i++)
		{
			for(j=0;j<m-1;j++)
			{
				if(c[i][j]!=-1)
				{
					k=c[i][j];
					if(c[i][j+1]!=-1)
					{	l=c[i][j+1];		v[k].addedge(l);		v[l].addedge(k);		}
					if(c[i+1][j]!=-1)
					{	l=c[i+1][j];		v[k].addedge(l);		v[l].addedge(k);		}
				}
			}
		}
		for(j=0;j<m-1;j++)
		{
			if(c[n-1][j]!=-1)
			{
				k=c[n-1][j];
				if(c[n-1][j+1]!=-1)		{	l=c[n-1][j+1];	v[k].addedge(l);	v[l].addedge(k);	}
			}
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
			{     d[*p]=d[t]+1;  v[*p].c=gray;   q.push(*p);  }
		    p++;
	    	}
	    }
	    maxi=-1;
	    for(int i=0;i<sz;i++)
	    {
	    	if(maxi<d[i])
	    	{  maxi=d[i];  k=i; }
		}
		return k;
    }
};
int main()
{
	int m,n,k,i,j,vtx;
	int t;
	s(t);
	while(t--)
	{
		s(m);	s(n);
		k=0;
		char d;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				cin>>d;		if(d=='.') 	c[i][j]=k++;	else c[i][j]=-1;
			}
		}
		vtx=k;
		Graph g(vtx);
		g.inputgraph(m,n);
		k=g.Breadthfirstsearch(0,vtx);
		k=g.Breadthfirstsearch(k,vtx);
		p(maxi);	nl;
	}
	
}

