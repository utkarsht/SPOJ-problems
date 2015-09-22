//      template by Utkarsh trivedi
//      problem id-                       Based on-
#include<stdio.h>
#define s(x) scanf("%d",&x)
#define p(x) printf("%d",x)
#define sl(x) scanf("%lld",&x)
#define pl(x) printf("%lld",x)
#define nl   printf("\n")
#define chk   printf("hello    ")
typedef long long ll;
typedef unsigned long long ull;

#include<iostream>
#include<set>
#include<map>
#include<list>
#include<vector>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;

// for fast input include below one
/*

*/
int first(int arr[], int low, int high, int x, int n)
{
  if(high >= low)
  {
    int mid = (low + high)/2;  /*low + (high - low)/2;*/
    if( ( mid == 0 || x > arr[mid-1]) && arr[mid] == x)
      return mid;
    else if(x > arr[mid])
      return first(arr, (mid + 1), high, x, n);
    else
      return first(arr, low, (mid -1), x, n);
  }
  return -1;
}
 
 
/* if x is present in arr[] then returns the index of LAST occurrence 
   of x in arr[0..n-1], otherwise returns -1 */
int last(int arr[], int low, int high, int x, int n)
{
  if(high >= low)
  {
    int mid = (low + high)/2;  /*low + (high - low)/2;*/
    if( ( mid == n-1 || x < arr[mid+1]) && arr[mid] == x )
      return mid;
    else if(x < arr[mid])
      return last(arr, low, (mid -1), x, n);
    else
      return last(arr, (mid + 1), high, x, n);      
  }
  return -1;
}
 int count(int arr[], int x, int n)
{
  int i; // index of first occurrence of x in arr[0..n-1]
  int j; // index of last occurrence of x in arr[0..n-1]
     
  /* get the index of first occurrence of x */
  i = first(arr, 0, n-1, x, n);
 
  /* If x doesn't exist in arr[] then return -1 */
  if(i == -1)
    return i;
    
  /* Else get the index of last occurrence of x. Note that we 
      are only looking in the subarray after first occurrence */  
  j = last(arr, i, n-1, x, n);     
    
  /* return count */
  return j-i+1;
}

int main()
{
	
	int n,i,j;
	s(n);
	int a[n],b[n],c[n],d[n];
	int ar[n*n],br[n*n];
	for(i=0;i<n;i++)
	{
		s(a[i]);   s(b[i]);   s(c[i]);   s(d[i]);
	}
	int k=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			ar[k++]=a[i]+b[j];
		}
	}
	k=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			br[k++]=(-1)*(c[i]+d[j]);
		}
	}
	sort(br,br+k);
	int pn;
	ll ct=0;
	for(i=0;i<k;i++)
	{
		pn=count(br,ar[i],k);
		if(pn!=-1)    ct+=pn;
	}
	pl(ct);
}
