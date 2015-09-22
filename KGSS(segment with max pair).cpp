#include<bits/stdc++.h>
using namespace std;
#define M 100004
typedef pair<int,int> ii;
int n;
int a[M];
ii seg[2*M];
 
int max(int a,int b,int c)
{
	return max(a,max(b,c));
}
void make_tree(int lo,int hi,int idx)
{
	if(hi == lo)
	{
		seg[idx].first = a[lo];
		seg[idx].second = -1;
		return;
	}
	
	int mid = (lo + hi)/2;
	make_tree(lo,mid,2*idx);
	make_tree(mid+1,hi,2*idx+1);
	
	if(seg[2*idx].first >= seg[2*idx+1].first)
	{
		seg[idx].first = seg[2*idx].first;
		seg[idx].second = max(seg[2*idx+1].first , seg[2*idx].second , seg[2*idx+1].second);
	}
	else
	{
		seg[idx].first = seg[2*idx+1].first;
		seg[idx].second = max(seg[2*idx].first , seg[2*idx].second , seg[2*idx+1].second);
	}
}
 
void update(int lo,int hi,int idx,int pos,int newval)
{
	if(pos<lo || pos>hi)
        return;
	if(hi == lo)
	{
		a[pos] = newval;
		seg[idx].first = newval;
		return;
	}
 
	int mid = (lo + hi)/2;
	update(lo,mid,2*idx,pos,newval);
	update(mid+1,hi,2*idx+1,pos,newval);
	
	if(seg[2*idx].first >= seg[2*idx+1].first)
	{
		seg[idx].first = seg[2*idx].first;
		seg[idx].second = max(seg[2*idx+1].first , seg[2*idx].second , seg[2*idx+1].second);
	}
	else
	{
		seg[idx].first = seg[2*idx+1].first;
		seg[idx].second = max(seg[2*idx].first , seg[2*idx].second , seg[2*idx+1].second);
	}
}
 
ii query(int lo,int hi,int idx,int i,int j)
{
	if(i<=lo && j>=hi)
        return seg[idx];
    else if(i>hi || j<lo)
        return ii(-1,-1);
    else
    {
    	int mid = (lo+hi)/2;
    	ii a = query(lo,mid,2*idx,i,j);
    	ii b = query(mid+1,hi,2*idx+1,i,j);
    	ii c;
    	c.first = max( a.first , b.first );
		if(a.first >= b.first)
		{
			c.first = a.first;
			c.second = max(b.first , a.second , b.second);
		}
		else
		{
			c.first = b.first;
			c.second = max(a.first , a.second , b.second);
		}	
		return c;
    }
}
 
int main()
{
	int q,x,y;
	ii value;
	char c;
	cin>>n;
	for(int i=0;i<n;i++)	cin>>(a[i]);
	make_tree(0,n-1,1);
	
	cin>>q;
	while(q--)
	{
		cin>>c;
		cin>>x>>y;
		if(c=='U')		update(0,n-1,1,x-1,y);
		else
		{
			value = query(0,n-1,1,x-1,y-1);
			cout<<(value.first + value.second)<<endl;
		}
	}
} 
