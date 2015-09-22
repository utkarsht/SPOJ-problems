#include<stdio.h>
#include<string.h>
#define s(x) scanf("%d",&x)
#define p(x) printf("%d",x)
#define nl   printf("\n")
#define M 1000000007
#define sz 100002
char str[sz];
int last[128];
int dp[sz];
int main()
{
	int t,l;
	s(t);
	while(t--)
	{
		memset(&dp,0,sizeof(dp));
		memset(&last,-1,sizeof(last));
		scanf("%s",str);
		int l=strlen(str);
		dp[0]=1;	dp[1]=2;
		last[str[0]] = 0;
		for(int i=2;i<l;i++)
		{
			dp[i] = (2*dp[i-1]) % M;
			last[str[i]] = i;
			if(last[str[i]]>0)	dp[i] -= dp[last[str[i]]-1];
		}
		p(dp[l-1]);		nl;
	}
}
