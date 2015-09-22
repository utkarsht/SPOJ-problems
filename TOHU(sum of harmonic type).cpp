#include<stdio.h>
#include<math.h>
int main()
{
	int t;
	long n;
	double ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%ld",&n);
		if(n==1)	{	printf("%.11f\n",2.0/3);		continue;	}
		if(n==2)	{	printf("%.11f\n",2.0/3 + 1.0/24);			continue;	}
		if(n==3)	{	printf("%.11f\n",2.0/3 + 1.0/24 + 1.0/60);			continue;	}
		if(n==4)	{	printf("%.11f\n",2.0/3 + 1.0/24 + 1.0/60 + 1.0/120);			continue;	}
		else
		{
			ans = 2.0/3 + 1.0/4 - 1.0/6 ;
			ans = ans + 1.0/(2*(n+2)) - 1.0/(2*(n+1));
			printf("%.11f\n",ans);
		}
	}
}
