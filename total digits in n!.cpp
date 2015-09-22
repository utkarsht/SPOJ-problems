// digits in n!   [(log(2PIn)/2+n(logn-loge))/log10]+1  formula used

#include<stdio.h>
#include<math.h>
int main()
{
    long double a=0.3990899341790575247825035915077;
    long double b=0.4342944819032518276414969;
    long long n;
    int t;
    scanf("%d",&t);
    while(t--)
    {
    	scanf("%lld",&n);
    	if(n==0 || n==1)    {  printf("1\n");   continue;   }
    	long double k=log10(n);
    	long long ans = floor(a+ (double)k/2 + (double)n*(k-b));
    	printf("%lld\n",ans+1);
    }
}
