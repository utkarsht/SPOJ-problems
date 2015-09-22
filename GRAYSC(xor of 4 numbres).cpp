/*		In this question main thing is by pigeonhole principle ( refer editorial of this problem )
		if n>130 it is always possible to get a quadruple of xor 4 so we need to chk only for less than 130 
		which we can do O(n^3 log n)
*/
#include<stdio.h>
#include<string.h>
#include<math.h>
#define s(x) scanf("%d",&x)
#define p(x) printf("%d",x)
#define sl(x) scanf("%lld",&x)
#define pl(x) printf("%lld",x)
#define gap	printf(" ")
#define nl   printf("\n")
#define chk   printf("hello    ")
#define F	for(int i=0;i<n;i++)
#define mset(x,val)	 memset(&x,val,sizeof(x))
#define all(c) (c).begin(),(c).end()
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
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
 

 
bool brute(ull *a,ull n)
{
	ull m,i,j,k,l;
	for(i=0;i<n-3;i++)
	{
		for(j=i+1;j<n-2;j++)
		{
			for(k=j+1;k<n-1;k++)
			{
				for(l=k+1;l<n;l++)
				{
					 if((a[i]^a[j]^a[k]^a[l])==0)
					 	return 1;
				}
			}
		}
	}
	return 0;
}
 
int main()
{
	ull n;
	ull a[100001];
	s(n);
	F	s(a[i]);
	if(n>70)
		cout<<"Yes\n";
	else
	{
		if(brute(a,n))
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
} 
