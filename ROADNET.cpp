// http://www.geeksforgeeks.org/dynamic-programming-set-16-floyd-warshall-algorithm/

#include<stdio.h>
#include<string.h>
#include<math.h>
#define s(x) scanf("%d",&x)
#define p(x) printf("%d",x)
#define sl(x) scanf("%lld",&x)
#define pl(x) printf("%lld",x)
#define gap	printf(" ")
#define nl   printf("\n")
#define sz 202
#define MAX 2147483647
int main()
{
	int t,i,j,k,n,count;
	int a[sz][sz];
	bool flag;
	s(t);
	while(t--)
	{
		s(n);
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
				s(a[i][j]);
		}
	
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				flag=0;
				for(k=0;k<n;k++)
				{
					if(i==k || j==k)	continue;	
					else
					{	
						if(a[i][j]==a[i][k]+a[k][j])
						{	  flag=1;	break;	}
					}
				}
				if(flag==0)
				{	p(i+1);	gap;	p(j+1);	nl;	}
			}
		}
	}
}
