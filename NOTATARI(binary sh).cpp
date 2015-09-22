//      template by Utkarsh trivedi
//      problem id-    not a triangle                   Based on-  binary search
#include<stdio.h>
#define s(x) scanf("%d",&x)
#define p(x) printf("%d",x)
#define sl(x) scanf("%lld",&x)
#define pl(x) printf("%lld",x)
#define nl   printf("\n")
typedef long long ll;
typedef unsigned long long ull;

#include<iostream>
#include<algorithm>
using namespace std;


int bs(int *a,int low,int high,int k)
{
	int save=high;
	int mid;
	if(low==high)
	{
		if(k<a[low])  return 1;
		else return 0;
	}
	if(a[high]<=k)    return 0;
	while(low<high)
	{
		mid=low+(high-low)/2;
		if(a[mid]>k)
			high=mid;
		else
			low=mid+1;
	}
	//if ()
	return (save-low+1);
}
int main()
{
	int n,b,c,rev,count;
	while(true)
	{
		s(n);
		count=0;
		if(!n)  break;
		int a[n];
		for(int i=0;i<n;i++)
		{
			s(a[i]);
		}
		sort(a,a+n);
		
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n-1;j++)
			{
				c=a[i]+a[j];
				rev=bs(a,j+1,n-1,c);
			//	printf("%d   %d     %d\n",i,j,rev );
				count+=rev;
			}
		}
		p(count);
		nl;
	}

}
