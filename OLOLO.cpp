#include<stdio.h>
#define s(x)  scanf("%ld",&x) 
int main()
{
	long t,n,ans=0;
	s(t);
	int a[t];
	while(t--)
	{
		s(n);
		ans=ans^n;
	}
	printf("%ld\n",ans);  
	return 0;
}
