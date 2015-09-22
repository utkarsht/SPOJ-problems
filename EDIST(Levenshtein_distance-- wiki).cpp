#include<stdio.h>
#include<cstring>
#include<string.h>
int min(int i , int j, int k)
{
	if(i <= j)
	{
		if(i <= k) return i;
		return k;
	}
	else
	{
		if(j <= k) return j;
		return k;
	}
}
int dp[202][202];             //SIZE SHOULD BE 2000
int main()
{
	int l,m,i,j,t;
	char str1[2002],str2[2002];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s %s",str1,str2);
		l=strlen(str1);     m=strlen(str2);
		memset(&dp,0,l*m*sizeof(int));
		for(i=0;i<=l;i++)
		dp[i][0]=i;
		for(j=0;j<=m;j++)
		dp[0][j]=j;
		for(i=1;i<=l;i++)
		{
			for(j=1;j<=m;j++)
			{
				if(str1[i-1]==str2[j-1])
					dp[i][j]=dp[i-1][j-1];
				else
				{
					dp[i][j]=min(dp[i-1][j]+1,dp[i][j-1]+1,dp[i-1][j-1]+1);         // insertion in first and second ,  substitution third term
				}
			}
		}
		for(int i=0;i<=l;i++)
		{
			for(int j=0;j<=m;j++)
			{
				printf("%d  ",dp[i][j]);
			}
			printf("\n");
		}
		printf("%d\n",dp[l][m]);
	}	
}
