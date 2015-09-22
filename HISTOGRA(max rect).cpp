//	http://www.geeksforgeeks.org/largest-rectangle-under-histogram/
// 	Better - http://tech-queries.blogspot.in/2011/03/maximum-area-rectangle-in-histogram.html

#include<iostream>
#include<stack>
#define MIN -2147483647
using namespace std;
typedef long long ll;
ll max_area(ll a[],ll n)
{
	ll i=0,tp;	
	ll area_with_top;
	ll maxarea = MIN;
	stack<ll> st;
	while(i<n)
	{
		if(st.empty() || a[i]>=a[st.top()])
			st.push(i++);
		else
		{
			tp = st.top();		st.pop();
			area_with_top = a[tp] * ( st.empty() ? i : i-st.top()-1 );
			if(area_with_top > maxarea)
				maxarea = area_with_top;
		}
	}
	while(!st.empty())
	{
		tp = st.top();		st.pop();
		area_with_top = a[tp] * ( st.empty() ? i : i-st.top()-1 );
		if(area_with_top > maxarea)
			maxarea = area_with_top;
	}
	return maxarea;
}
int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	ll n;
	ll a[100002];
	while(1)
	{
		cin>>n;			if(!n)	break;	
		for(ll i=0;i<n;i++)		cin>>a[i];
		cout<<max_area(a,n)<<endl;
	}
}
