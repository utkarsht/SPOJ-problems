#include<bits/stdc++.h>
#define MAX 100002
using namespace std;
int a[MAX];
int aux[MAX];
int inversion = 0;

void merge(int low,int mid,int high)
{
	int i,j,k=low;
	i = low;  j = mid+1;
	while(i<=mid && j<=high)
	{
		if(a[i]>a[j])
		{	aux[k++] = a[j];   j++;   inversion+=(mid-i+1);	}
		else 
		{	aux[k++] = a[i];   i++;		}	
	}
	while(i<=mid)
		{	aux[k++] = a[i];   i++;		}
	while(j<=high)
		{	aux[k++] = a[j];   j++;  	}
		
	for(i=low;i<=high;i++)
		a[i] = aux[i];
}
void mergesort(int low,int high)
{
	if(low==high)	return;
	int mid = low + (high-low)/2;
	mergesort(low,mid);
	mergesort(mid+1,high);
	merge(low,mid,high);	
}

int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		inversion = 0;
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>a[i];
		mergesort(0,n-1);
		cout<<inversion<<endl;
	}
}
