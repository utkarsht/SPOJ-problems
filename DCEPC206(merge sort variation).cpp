//https://github.com/srikk595/Spoj-/blob/master/DCEPC206-6813438-src.cpp
//  key point is we will break the array in two parts each time so O(nlogn)
//  same as merge sort , extra thing will be that when merging we have two
//	arrays A and B(let)		if in merged sorted array "an element from array A
//	is going then we chk how many elements are remaining in B for going into merged array
//	and this count tells us 'that element of A is smaller than this much elements of 
//  B directly (because array is sorted)'  so
//	we multiply that element with this count and add them in sum .  "


#include<iostream>
using namespace std;
typedef long long ll;
#define sz 100004

ll sum = 0;

int a[sz];
int aux[sz];

void merge(int lo,int mid,int hi)
{
	int i,j;
	
	for(i=lo;i<=hi;i++)
		aux[i]=a[i];
		
	i=lo; j=mid+1;
	int k=lo;
	
	while(i<=mid && j<=hi)
	{
		if(aux[i] < aux[j])
		{
			sum += (ll) (hi-j+1)*aux[i];
			a[k++] = aux[i++];
		}
		else
		{
			a[k++] = aux[j++];
		}
	}
	
	while(i<=mid)
		a[k++] = aux[i++];
	while(j<=hi)
		a[k++] = aux[j++];
}

void sort(int low,int high)
{
	if(low==high)		return;
	int mid = (low+high)/2;
	
	sort(low,mid);
	sort(mid+1,high);
	merge(low,mid,high);
}

int main()
{
	int t,i,n,maxv;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		sort(1,n);
		cout<<sum<<endl;
	}
}
