//  Varient of knapsack problem here key point is that any value can be taken many times so simple algo will not work
//	so here , we will start a loop from min weight and loop through up to weight of bag and check knapscak condition
//	if it satisfies we will take it here term cost[j-w[i] ] may go to same value again so "taking one indexed dp and starting from smallest
//  value and after loop checking codition that cost[total_wt] is changed or not " is key point.

#include<iostream>
#include<string.h>
#define INF 99999999
using namespace std;
int min(int a, int b) { return (a > b)? b : a; }
int main()
{
	int t,u,tw,n,i,j;
	cin>>t;
	while(t--)
	{
		cin>>u>>tw;
		tw=tw-u;
		cin>>n;
		int p[n],w[n];
		for(i=0;i<n;i++)
		cin>>p[i]>>w[i];
		int cost[tw+1];
		for(i=0;i<=tw;i++)		cost[i]=INF;
		cost[0]=0;
		for(i=0;i<n;i++)
		{
			for(j=w[i];j<=tw;j++)	 // this loop shows that for particular money p[i] we can take it many times.
			{
					cost[j] =   min ( cost[j-w[i]] + p[i] , cost[j] );
			}
		}
		if(cost[tw]!=INF)
		cout<<"The minimum amount of money in the piggy-bank is "<<cost[tw]<<"."<<endl;
		else
		cout<<"This is impossible.\n";
	}
}
