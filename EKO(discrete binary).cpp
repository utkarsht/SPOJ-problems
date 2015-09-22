#include<bits/stdc++.h>
using namespace std;
#define MAX 1000002
typedef long long ll;
ll total;		int a[MAX];
int n;
ll getht(ll x)
{
	ll sum = 0;
	for(int i=0;i<n;i++)	
	{
		sum += (x>a[i]) ? 0 : (a[i]-x) ;
	}
	return sum;
}
void bsch(int beg,int end,ll require)
{
	int mid = beg + (end-beg)/2;            
	while(beg<=end)  
	{
	//	cout<<mid<<endl;
		if(getht(mid)<require)
			end=mid-1;
		else
			beg=mid+1;
		mid=(beg+end)/2;
		
	}
	cout<<end<<endl;
}
int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	int maxv = 0;
	cin>>n>>total;
	for(int i=0;i<n;i++)
{		cin>>a[i];
		maxv = max(a[i],maxv);
}	
bsch(0,maxv,total);
}


