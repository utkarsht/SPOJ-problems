#include<stdio.h>
#include<math.h>
int gcd (int a,int b)
{
	if(b==0) return a;
	else return gcd(b,a%b);
}
int main()
{
	int t,a,b,n,i,k;
	scanf("%d",&t);
	while(t--)
	{
		int sum=0;
		scanf("%d %d",&a,&b);
		n=gcd(a,b);
		if(n==1)  {   printf("1\n");  continue; }
		if(n==2)  {   printf("2\n");  continue; }
		int k=sqrt(n);
		for(i=2;i<=k;i++)
		{
			if(n%i==0)
			{
				if(i==n/i)   sum++;
				else sum+=2;
			}
		}
		sum++;
		printf("%d\n",sum+1);
	}
}
