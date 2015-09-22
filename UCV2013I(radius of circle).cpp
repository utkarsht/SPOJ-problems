#include<stdio.h>
#include<math.h>
#define scanint(x)  scanf("%d",&x)
#define PI   3.14159265358979 
int main()
{
	int r,n;
	while(1)
	{
		scanint(r);    scanint(n);
		if(r==0  &&  n==0)   break;
		n=n+n;
		double result=sin((double)PI/n);
		printf("%.2f\n",r/result);
	}
}

