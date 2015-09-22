#include<stdio.h>
#define scanint(x) scanf("%lld",&x)
long long gcd(long long a, long long b)
{
	if (b==0)
		return a;
	else
		return gcd(b,a%b);
}
int main()
{
	long long i,n;
	while(1)
	{
		long long sum=0;
		scanint(n);
		if(n==0)   break;
		long long save=0;
		long long a[n],b[n],c[n];
		for(i=0;i<n;i++)
		{
		   scanint(a[i]);   scanint(b[i]);  scanint(c[i]);  
		   save=gcd(a[i],save);
		   save=gcd(b[i],save);
		   save=gcd(c[i],save);
	    }
		for(i=0;i<n;i++)
		{
			a[i]=a[i]/save;    b[i]=b[i]/save;   c[i]=c[i]/save; 
			sum+=a[i]*b[i]*c[i];
		}
		printf("%lld\n",sum);
	}
}
