#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#define s(x) scanf("%d",&x)
#define p(x) printf("%d",x)
using namespace std;
#define sz 100
int main()
{
	int i,n,m,count;
	string str[sz];
	int a[sz];
	while(1)
	{
		count=0;
		s(n);	s(m);
		if(!n && !m)	break;
		memset(&a,0,sizeof(a));
		for(i=0;i<n;i++)		cin>>str[i];
		sort(str,str+n);
		str[n]="BUNDUM";
		for(i=1;i<=n;i++)
		{
			if(str[i]==str[i-1])
				count++;
			else
			{	a[count+1]++;		count=0;	}
		}
		for(i=1;i<=n;i++)
		{
			printf("%d\n",a[i]);
		}
	}
}
