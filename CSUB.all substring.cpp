#include<stdio.h>
int main()
{
	int t,n,i;
	char str[n+2];
	scanf("%d",&t);
	while(t--)
	{
		int count=0;
		scanf("%d",&n);
		scanf("%s",str);
		for(i=0;i<n;i++)
		{
			if(str[i]=='1')
			count++;
		}
		printf("%d\n",(count*(count+1))/2);
	}
}
