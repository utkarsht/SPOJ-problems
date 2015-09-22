#include <cstdio>
#include <algorithm>
#define s(x) scanf("%d",&x)
#define p(x) printf("%d          ",x)
#define nl   printf("\n")
#define sz 100

#define chk   printf("hello    ")
void print(int *p,int l)
{
	for(int i=0;i<l;i++)
		{   p(p[i]);        }
}
using namespace std;

 
/* if x is present in arr[] then returns the index of FIRST occurrence 
   of x in arr[0..n-1], otherwise returns -1 */
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
	int n;
	s(n);
	int i,j,k,l=0;
	int a[sz],b[sz],num[100];
	for(i=0;i<n;i++)
		s(num[i]);
	for(i=0;i,i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			for(k=0;k<n;k++)
			{
				a[l++]=num[i]*num[j]+num[k];
			}
		}
	}
	int l1=0;
	for(i=0;i,i<n;i++)
	{
		if(num[i]!=0)
		{
		for(j=0;j<n;j++)
		{
			for(k=0;k<n;k++)
			{
				b[l1++]=num[i]*(num[j]+num[k]);
			}
		}
		}
	}
	//nl; chk;p(l1); nl;
	//print(a,l);     nl;      print(b,l1);      nl;
	sort(a,a+l);           sort(b,b+l1);
	//print(a,l);     nl ;   print(b,l1);     nl;
	int ct=0,c ;
	for(i=0;i<l;i++)
	{
		 c=count(b,a[i],l1);
		 if(c!=-1)     ct+=c;   
	}
	p(ct);
}
