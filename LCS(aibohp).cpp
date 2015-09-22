//      template by Utkarsh trivedi
//      problem id-                       Based on-      LCS   minimum addition to make string palindrome= string length - lcs(string , reverse string)
#include<stdio.h>
#include<cstring>
#define s(x) scanf("%d",&x)
#define p(x) printf("%d",x)
#include<map>
#include<vector>
#define nl   printf("\n")

#define sz 610
using namespace std;

int max(int a,int b)
{
	return (a>b) ? a : b;
}
void reverse(char *str)
{
	int l=strlen(str);		char temp;
	for(int i=0;i<l/2;i++)
	{
		temp=str[i];
		str[i]=str[l-i-1];
		str[l-i-1]=temp;
	}
}
int LCS(char *str1,char *str2)
{
	int L[2][sz];
	int i,j;	int m=strlen(str1);		int n=strlen(str2);
	memset(&L,0,2*sz*sizeof(int));
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(str1[i-1]==str2[j-1])
			{	L[i%2][j]=L[(i-1)%2][j-1]+1;  }
			else
			{	L[i%2][j]=max(L[(i-1)%2][j],L[i%2][j-1]);	}
		}
	}
	return L[m%2][n];
}
int main()
{
	char str[sz],rev[sz];	int common,l;
	int t;
	s(t);
	while(t--)
	{
		printf("Enter first string\n");		scanf("%s",str);	
		//strcpy(rev,str);
		//reverse(rev);
		printf("Enter second string\n");	scanf("%s",rev);
		common=LCS(str,rev);
		p(common);
		//p(l-common);
		nl;
	}
	
}
