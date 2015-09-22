#include<iostream>
using namespace std;
int main()
{
	long m,n,i,j,sum1,sum2,sum,flag1,flag2;
	while(1)
	{
		cin>>m;
		if(m==0)   break;
		int a[m];
		for(i=0;i<m;i++)
		cin>>a[i];
		cin>>n;
		int b[n];
		for(i=0;i<n;i++)
		cin>>b[i];
		i=0;  j=0;
		sum1=sum2=sum=0;
		flag1=flag2=0;
		while(i<=m-1|| j<=n-1)
		{
		if(flag2==1  || a[i]<b[j])
		{  
		    sum1+=a[i];
		    i++;
		    if(i>=m)   flag1=1;
		}
		else if(flag1==1 || b[j]<a[i])
		{
			sum2+=b[j];
			j++;
			if(j>=n)   flag2=1;
		}
		else
		{
			if(sum1>=sum2)
			sum+=a[i]+sum1;
			else
			sum+=a[i]+sum2;
			i++; j++;
			if(i>=m)   flag1=1;
			if(j>=n)   flag2=1;
			sum1=sum2=0;
		}
	}
		sum+=(sum1>=sum2)?sum1:sum2;
		cout<<sum<<endl;
	}
}
