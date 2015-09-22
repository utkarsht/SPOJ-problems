//	Horrible   help taken from - http://isharemylearning.blogspot.in/2012/08/lazy-propagation-in-segment-tree.html

#include<bits/stdc++.h>
#define M 400000					//  n  = 10^5		so M = 2^( ceil(log n) + 1 )
using namespace std;
typedef long long ll;

long long st[M];
bool color[M];
long long helper[M];

long long maxi(long long a,long long b)
{
	if(a>b)		return a;
	else		return b;
}

long long merge(long long a,long long b)
{
	return (a+b);
}

/*														// No need to construct all values are zero initially
void construct(int low,int high,int idx)
{
	if(low == high)
	{
		st[idx] = a[low];
		return;
	}
	int mid = (low+high)>>1;
	construct(low,mid,2*idx+1);
	construct(mid+1,high,2*idx+2);
	st[idx] = merge( st[2*idx+1] , st[2*idx+2] );
}
*/

void update_lazy(int low,int high,int i,int j,int idx,ll val)
{
	if(i>high ||  j<low)
	{
		return;
	}
	if(low == high)
	{
		st[idx] = st[idx] + val;
		if(color[idx] == true)
		{
			st[idx] += helper[idx];
			helper[idx] = 0;
		}
		return;
	}

	if(i<=low && j>=high)
	{
		st[idx] += val*(high-low+1);
		color[2*idx+1] = color[2*idx+2] = 1;
		helper[2*idx+1] += val;
		helper[2*idx+2] += val;
		return;
	}
	else if (i <= high && j >high)
        st[idx] += (val*(high-i+1));
    else if (low <= j && i <low)
        st[idx] += (val*(j-low+1));
    else if (i >= low && j <= high)
        st[idx] += (val*(j-i+1));
            
	int mid = (low+high)/2;
	update_lazy(low,mid,i,j,2*idx+1,val);
	update_lazy(mid+1,high,i,j,2*idx+2,val);
	
//	st[idx] = merge(st[2*idx+1],st[2*idx+2]);
//	st[idx] = val*( min(j,high) - maxi(low,i) + 1 );
}
ll query(int low,int high,int i,int j,int idx)
{
	if(i>high ||  j<low)
	{
		return 0;
	}
	if(color[idx] == 1)
	{
		st[idx] += helper[idx] * (high-low+1);
		color[idx] = false;
		if(low != high)
		{
			color[2*idx+1] = color[2*idx+2] = true;
			helper[2*idx+1] += helper[idx];
			helper[2*idx+2] += helper[idx];
		}
		helper[idx] = 0;
	}
	if(i<=low && j>=high)
	{
		return st[idx];
	}
	int mid = (low+high)>>1;
	return merge( query(low,mid,i,j,2*idx+1) , query(mid+1,high,i,j,2*idx+2) );
}
int main()
{
	cin.sync_with_stdio(0);
	cout.sync_with_stdio(0);
	ll t,val,i,j,n,q;
	bool ch;
	cin>>t;
	while(t--)
	{
		cin>>n>>q;
		while(q--)
		{
			cin>>ch>>i>>j;
			i--;	j--;
			if(ch == 0)
			{
				cin>>val;
				update_lazy(0,n-1,i,j,0,val);
			//	cout<<query(0,n-1,i,j,0)<<endl;
			}
			else
				cout<<query(0,n-1,i,j,0)<<endl;
		/*	for(int i=0;i<=14;i++)
				cout<<st[i]<<"("<<i<<")" << "   ";
			cout<<endl;
			for(int i=0;i<=14;i++)
				cout<<helper[i]<<"("<<i<<")"<< "   ";
			cout<<endl;
			for(int l=0;l<n;l++)
				cout<<query(0,n-1,l,l,0)<<"   ";
			cout<<endl;*/
		}
	}
}
