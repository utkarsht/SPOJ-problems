#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;
void swap(char&a ,char& b)
{
	char t;
	t=a;  
	a=b;
	b=t;
}
int main()
{
	int t,n,i,j,l;
	char k,min;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		char a[n];
		for(i=0;i<n;i++)
		cin>>a[i];
		for(i=n-1;i>=0;i--)
		{
			if(a[i]>a[i-1] && i>0)
			{
				k=a[i-1];
				min=a[i];   l=i;
				for(j=i;j<n;j++)
				{
					if(a[j]<min  && a[j]>k)
					{  min=a[j];  l=j;  }
				}
				swap(a[i-1],a[l]);
				sort(a+i,a+n);
				break;
			}
			
		}
		if(i==-1)     cout<<i<<endl;
		else
		{
			for(i=0;i<n;i++)
		    cout<<a[i];
		    cout<<endl;
		}
	}
}
