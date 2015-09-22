#include<iostream>
#include<math.h>
#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;
int val(char c)
{
	if(c>='0' && c<='9')
		return (int)c-'0';
	else
		return (int)c-'A'+10;
}
char reval(int num)
{
	if(num>=0  &&  num<=9)
		return (char)(num+'0');
	else
		return (char)(num-10+'A');
}
void strev(char *str)
{
	int l=strlen(str);		char temp;
	for(int i=0;i<l/2;i++)	
	{
		temp = str[i];
		str[i] = str[l-i-1];
		str[l-i-1] = temp;
	}
}
int todeci(char *s,int n)
{
	int l=strlen(s);	int j=0;
	int base=1;	int num=0;
	for(int i=l-1;i>=0;i--)
	{
		num += val(s[i])*base;
		base=base*n;
	}
	return num;
} 
char* fromdeci(char *str,int num,int m)
{
//	if(m==10)	{	sprintf(str,"%s",num);		}
//	else
	{
		int k=0;
		while(num>0)
		{
			str[k++] = reval(num%m);
			num/=m;
		}
		str[k]='\0';	
		strev(str);
	}
}
int main()
{
	int m,n,space,i,num;
	char str[50],ans[50];
	while(cin>>str)
	{
		scanf("%d %d",&n,&m);
		num = todeci(str,n);
//		cout<<num<<endl;
		fromdeci(ans,num,m);
//		cout<<ans<<endl;
		space = 7 - strlen(ans) ;
		if(space<0)
			printf("  ERROR\n");
		else
		{
			for(i=0;i<space;i++)
				printf(" ");
			printf("%s\n",ans);	
		}
	}
}
