#include<bits/stdc++.h>
#define M 100005
#define MAX 2147483647
#define MIN -MAX
using namespace std;
typedef pair<int,int> ii;

int b[M];
ii st[M];

ii combine(ii a,ii b)
{
	ii temp;
	temp.first = min(a.first,b.first);
	temp.second = max(a.second,b.second);
	return temp;
}
double get(ii p1)
{
	return (( p1.first + (p1.second - p1.first)/2.0 ));
}
double max(double a,int b,int c)
{
	return max(a, (double) max(b,c));
}
void construct(int lo,int hi,int idx)
{
	if(lo > hi)
		return ;
	if(lo == hi)
	{	st[idx] = ii(b[lo],b[lo]);	return;	  }
	
	int mid = (lo+hi)/2;
	construct(lo,mid,2*idx+1);
	construct(mid+1,hi,2*idx+2);

	st[idx] = combine(st[2*idx+1],st[2*idx+2]);
}

ii query(int lo,int hi,int i,int j,int idx)
{
	if(i>hi || j<lo)
		return ii(MAX,MIN);
	if(i<=lo && j>=hi)
		return st[idx];
	int mid = (lo+hi)/2;
	
	return combine(query(lo,mid,i,j,2*idx+1) , query(mid+1,hi,i,j,2*idx+2));
}
int main()
{
	cin.sync_with_stdio(0);
	cout.sync_with_stdio(0);
	int n,q,l,r;
	ii p1,p2,p3;
	double ans;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>b[i];
	construct(0,n-1,0);
	cin>>q;
	while(q--)
	{
		cin>>l>>r;
		if(l==0 && r==n-1)
		{
			p1 = query(0,n-1,l,r,0);
			ans = get(p1);
		}
		if(l==0)
		{
			p1 = query(0,n-1,l,r,0);
			p2 = query(0,n-1,r+1,n-1,0);
			ans = max(get(p1) , (double)(p2.second + p1.first));
		}
		else if(r==n-1)
		{
			p1 = query(0,n-1,l,r,0);
			p2 = query(0,n-1,0,l-1,0);
			ans = max(get(p1) , (double)(p2.second + p1.first));
		}
		else
		{
			p1 = query(0,n-1,l,r,0);
			p2 = query(0,n-1,0,l-1,0);
			p3 = query(0,n-1,r+1,n-1,0);
			ans = max(get(p1) , (p2.second + p1.first) , (p3.second + p1.first));
		}
		ans = ans*2;
		
			printf("%.1f\n",ans/2);
		//else
		//	printf("%d.0\n",floor(ans));
	}
}
