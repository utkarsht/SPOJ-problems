#include<bits/stdc++.h>
using namespace std;
#define MIN -2147483647
#define M 100
int maxarea(int a[],int n)
{
	int i = 0;
	int tp;		int area_with_top;
	stack<int> st;
	int max_area = MIN;
	while(i<n)
	{
		if(st.empty() || a[i]>=a[st.top()])
			st.push(i++);
		else
		{
			tp = st.top();		st.pop();
			area_with_top = a[tp] * (st.empty() ? i : i-st.top()-1);
			if(area_with_top > max_area)
				max_area = area_with_top;
		}
	}
	while(!st.empty())
	{
		tp = st.top();		st.pop();
		area_with_top = a[tp] * (st.empty() ? i : i-st.top()-1);
		if(area_with_top > max_area)
			max_area = area_with_top;
	}
	return max_area;
}
int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	int n , m , k , x ,y , q, i , j;
	int a[M][M];
	int ar[M];
	cin>>n>>m>>k;
//	memset(&a,0,sizeof(a));
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
			a[i][j] = 1;
	}
	for(i=0;i<k;i++)
	{
		cin>>x>>y;	x--;	y--;
		a[x][y] = 0;
	}
	for(i=1;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(a[i][j]!=0)		a[i][j] = 1 + a[i-1][j];
		}
	}
/*	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			cout<<a[i][j]<<"  ";
		}
		cout<<endl;
	}*/
	// Precompute area for all heights w.r.t. given row 
	for(i=0;i<n;i++)
	{
		ar[i] = maxarea(a[i],m);
	}
	for(i=0;i<n;i++)
		cout<<ar[i]<<"  ";			//  value of max histogram at each level
		
	
}
