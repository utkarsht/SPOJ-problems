#include<iostream>
#include<string>
#include<cstring>
using namespace std;
#define MAX 5002
typedef long long ll;
bool valid(char a,char b)
{
	int p=(int)a-'0';    int q=(int)b-'0';
	p=q*10+p;
	if(p>=10 and   p<=26) 		return 1;
	else return 0;
}

char str[MAX];
ll dp[MAX];
ll solve(char *s, int i)
{
	ll count = 0;
	if(i<=0)			return 1;
	if(dp[i]!=-1)		return dp[i];
	if(s[i]!='0')		count += solve(s,i-1);
	if(valid(s[i],s[i-1]))
	{	count += solve(s,i-2);	}
	dp[i] = count;
	return count;
}
int main()
{
	char str[MAX];
	while(1)
	{
		cin>>str; 
		int n = strlen(str);
		if(strcmp(str,"0")==0) 	  break;
		memset(dp,-1,sizeof(dp));
		cout<<solve(str,n-1)<<endl;
	}
}
