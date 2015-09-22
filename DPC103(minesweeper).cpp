#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int m,n;
bool ok(int i,int j)
{
	if(i>=0 && i<n && j>=0 && j<m)
		return 1;
	else
		return 0;
}
int val[101][101];
void increase(int i,int j)
{
	if(ok(i-1,j-1))		val[i-1][j-1]++;
	if(ok(i-1,j))		val[i-1][j]++;
	if(ok(i-1,j+1))		val[i-1][j+1]++;
	if(ok(i,j-1))		val[i][j-1]++;
	if(ok(i,j+1))		val[i][j+1]++;
	if(ok(i+1,j-1))		val[i+1][j-1]++;
	if(ok(i+1,j))		val[i+1][j]++;
	if(ok(i+1,j+1))		val[i+1][j+1]++;
}
int main()
{
	int i,j;	int o=1;
	char a[101][101];
	scanf("%d %d",&n,&m);
	while(m != 0 && n != 0) 
	{	
		memset(&val,0,sizeof(val));
		for(i=0;i<n;i++)
		{
				scanf("%s",a[i]);
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(a[i][j]=='*')
					increase(i,j);
			}
		}
		if(o>1)		printf("\n");
		printf("Field #%d:\n",o);
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(a[i][j]=='*')	printf("*");
				else				printf("%d",val[i][j]);
			}
			printf("\n");
		}
		
		scanf("%d %d",&n,&m);
		o++;
	}
}
