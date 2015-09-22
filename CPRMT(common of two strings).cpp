#include<iostream>
#include<algorithm>
#include<string.h>
#define z 97
using namespace std;
int main()
{
	string s,t;
	int i;
	char str[1000];		int a[26];
	while(cin>>s>>t)
	{
		memset(&a,0,sizeof(a));
		int k=0;
		for(i=0;i<s.length();i++)
		a[s[i]-z]++;
		for(i=0;i<t.length();i++)
		{
			if(a[t[i]-z]!=0)
			{
				str[k++]=t[i];  a[t[i]-z]--;
			}
		}
		sort(str,str+k);
		str[k]='\0';
		cout<<str<<endl;
	}
}
