#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<functional>
using namespace std;
void swap(long& a,long &b)
{
	long t;
	t=a;	a=b;	b=t;
}
long n;
bool sch(long *a,long k,int i)
{
/*	long low,high;
	int mid = low + (high-low)/2;
	while(low<high)
	{
		if(v[mid]<k)
			high=mid;
		else if(v[mid]==k)
			{	v.erase(mid);	return 1;	}
		else
			{	low=mid;	}
	}
	return 0;*/
	int p=i;
	for(;i<n;i++)
	{
		if(a[i]>=k)
		{
			break;
		}
	}
	if(i==n)	return 0;
//	cout<<i<<endl;
	swap(a[p],a[i]);
	return 1;
}
int main() 
{
    long t,i,d;
    cin>>t;
    while(t--)
    {
    	cin>>n>>d;
    	long flag=0;
    	long a[n],b[n];
    	for(i=0;i<n;i++)	cin>>a[i];
    	for(i=0;i<n;i++)	cin>>b[i];
    	sort(a,a+n,greater<long>());
    	sort(b,b+n);
    	for(i=0;i<n;i++)
    	{
    		if(sch(b,d-a[i],i)==1)
    		{
    			flag++;
    		}
    		else
    		break;
    	}	
    	if(flag==n)		{	cout<<"YES\n";	}
    	else			{	cout<<"NO\n";	}
    }
    return 0;
}

