#include<stdio.h>
#define s(x) scanf("%d",&x)
#define p(x) printf("%d",x)
#define nl   printf("\n")

int main()
{
	int t,n;
	int presum,dif,sum,sum1;
	s(t);
	while(t--)
	{
		s(n);
		int a[n];
		s(a[0]);
		presum=0;  dif=0; sum=0;
		for(int i=1;i<n;i++)
		{
			s(a[i]);
			dif=a[i]-a[i-1];
			sum1=2*sum + (i)*dif - presum;
			presum=sum;
			sum=sum1;
		//	pl(sum);      nl;
		}
		p(sum);
		nl;
	}
}
