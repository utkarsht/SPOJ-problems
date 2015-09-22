#include<stdio.h>
#include<string.h>
#define s(x) scanf("%d",&x)
#define p(x) printf("%d",x)
#define F(x)	for(int i=0;i<x;i++)
#include<iostream>
#include<set>
#include<vector>
using namespace std;

#define INF 2147483647
struct edge
{
	int b;
	int weight;
	edge(int second,int wt)
	{	b=second;	weight=wt;	}
};
struct vertex
{
	bool visited;
	int rank;
	vector<edge> adj;
	vertex()	{	visited=false;	 rank=INF;	}
};

bool operator<(vertex const& a,vertex const& b)
{
	return a.rank<b.rank;
}
int main()
{
	int t,i,j,a,b,e,n,weight,count,cost;
	char str[15];
	vertex temp;
	s(t);
	while(t--)
	{
		s(n);
		count=cost=0;
		vertex v[n];
		for(i=0;i<n;i++)
		{
			a=i;
			scanf("%s",str);
			s(e);
			for(j=0;j<e;j++)
			{	s(b);	s(weight);	b--;	v[i].adj.push_back(edge(b,weight));		}
		}
		set<vertex> pq;
		v[0].rank = 0;	v[0].visited=1;
		pq.insert(v[0]);
		while(!pq.empty())
		{
			temp=*pq.begin();		cost+=temp.rank;	count++;	pq.erase(pq.begin());
			for(i=0;i<temp.adj.size();i++)
			{
				vertex & ret = v[temp.adj[i].b];
				if(ret.visited==0)
				{	ret.rank = temp.adj[i].weight;		ret.visited=1;		pq.insert(ret);	}
				else
				{
					if(ret.rank>temp.adj[i].weight )
					{
						 pq.erase(pq.find( ret ));
						 ret.rank = temp.adj[i].weight;		ret.visited=1;		pq.insert(ret);
					}
				}
			}
		}
		printf("%d\n",cost);
	}

}
