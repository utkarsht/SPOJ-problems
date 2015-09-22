#include<bits/stdc++.h>
#define M 100005
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
int a[M];
int aux[M];
ll inv = 0;
void merge(int low,int mid,int high)
{
	int i = low, j =mid+1;	
	for(int i=low;i<=high;i++)
		aux[i] = a[i];
	int m = low;
	while(i<=mid && j<=high)
	{
		if(aux[i]<=aux[j])
		{
			a[m++] = aux[i++];	
		}
		else
		{
			a[m++] = aux[j++];	inv += (mid-i+1);	
		}
	}
	while(i<=mid)
		a[m++] = aux[i++];
	while(j<=high)
		a[m++] = aux[j++];
}
void mergesort(int low,int high)
{
	if(low == high)		return ;
	int mid =  low + (high-low)/2 ;
	mergesort(low,mid);
	mergesort(mid+1,high);
	merge(low,mid,high);
}
int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	int n;		vector<ii> v;	
	cin>>n;		int c,d;
	for(int i=0;i<n;i++)
	{
		cin>>c>>d;
		v.push_back(ii(c,d));
	}
	sort(v.begin(),v.end());
	for(int i=0;i<n;i++)
		a[i] = v[i].second;
	mergesort(0,n-1);
//	for(int i=0;i<n;i++)
//		cout<<a[i]<<"  ";
	cout<<inv<<endl;
}
