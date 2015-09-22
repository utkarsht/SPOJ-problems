#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int n,k=0,count=0,x,i,j;
	cin>>n;
	int a[n],b[n],c[n],d[n];
	bool flag;
	int sumab[n*n],sumcd[n*n],sumac[n*n],sumad[n*n],sumbc[n*n],sumbd[n*n];
	for(i=0;i<n;i++)
	scanf("%d %d %d %d",&a[i],&b[i],&c[i],&d[i]);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			sumab[k]=a[i]+b[j];
			sumac[k]=a[i]+c[j];
			sumad[k]=a[i]+d[j];
			sumbc[k]=b[i]+c[j];
			sumbd[k]=b[i]+d[j];
			sumcd[k]=c[i]+d[j];
			k++;
		}
	}
	k=0;
	count=0;
	sort(sumcd,sumcd+n*n);
	sort(sumbd,sumbd+n*n);
	sort(sumbc,sumbc+n*n);
	cout<<"\nab\n";
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		cout<<sumab[k++]<<"  ";
    }
    k=0;
    cout<<"\nac\n";
    for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		cout<<sumac[k++]<<"  ";
    }
    k=0;
    cout<<"\nad\n";
    for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		cout<<sumad[k++]<<"  ";
    }
    k=0;
    cout<<"\ncd\n";
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		cout<<sumcd[k++]<<"  ";
    }
    k=0;
    cout<<"\nbd\n";
    for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		cout<<sumbd[k++]<<"  ";
    }
    k=0;
    cout<<"\nbc\n";
    for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		cout<<sumbc[k++]<<"  ";
    }
    k=0;
    cout<<endl;
    k=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			x=sumab[k];
			flag=binary_search (sumcd,sumcd+n*n,-x);
			if(flag==1)  { cout<<x<<"x  ";  count++;  }
			
			x=sumac[k];
			flag=binary_search (sumbd,sumbd+n*n,-x);
			if(flag==1)  { cout<<x<<"x  ";  count++;  }
			
			x=sumad[k];
			flag=binary_search (sumbc,sumbc+n*n,-x);
			if(flag==1)  { cout<<x<<"x  ";  count++;  }
			
			k++;
		}
	}
	cout<<count<<endl;
}
