   //  Question based on discrete binary search 
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long Int;
Int a[100001],n,p;
Int f(Int x)
{
	Int last=a[0],count=0;
	for(Int i=1;i<n;i++)
	{
		if(a[i]-last>=x)
		{	 last=a[i];  count++;   }
		if(count==p-1)
		return 1;
	}
	return 0;
}
int bsch()
{
	Int low=1,high=a[n-1]-a[0],mid;
	while(low<high)
	{
		mid=low+(high-low)/2;
		if(f(mid)==1)
			low=mid+1;
		else
			high=mid;
	}
//	if(f(low)==0)   return 0;
	return low-1;
}
int main()
{
	Int t,i;
	cin>>t;
	while(t--)
	{
		cin>>n>>p;
		for(i=0;i<n;i++)
		cin>>a[i];
		sort(a,a+n);
		cout<<bsch()<<endl;
	}
}
