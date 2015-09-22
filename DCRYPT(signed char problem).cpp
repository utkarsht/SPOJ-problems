#include<iostream>
#include<string.h>
#include<cctype>
using namespace std;
#define sz 26
int main()
{
	int t,n;
	bool flag,flag2;
	cin>>t;
	char str[100000];
	while(t--)
	{
		cin>>n;
		if(n>=0 && n<=25)	flag=1;		else { flag=0;	n-=26; }
		cin>>str;
		int l=strlen(str);
		for(int i=0;i<l;i++)
		{
			flag2=0;
			if(str[i]=='.')
				str[i]=' ';
			else
			{
				if(flag)
				{	
					if(isupper(str[i]))			{	flag2=1;	}
					if(flag2==0	&& (int)str[i]+n>127)  { str[i] = (str[i] -26);   str[i] = (str[i]+n);  continue;}		//for signed char
					else	str[i] = (str[i] + n);	
					if(flag2)		{	if(str[i]>'Z')	str[i]-=26;	}
					else			{	if(str[i]>'z')	str[i]-=26;	}
				}
				else
				{
					if(isupper(str[i]))			{	flag2=1;	}
					if(flag2==0	&& (int)str[i]+n>127)  {	str[i] = (str[i] -26);   str[i] = (str[i]+n);  str[i]=toupper(str[i]);	continue;}	

					else str[i] = (str[i] + n);	
					if(flag2)		{	if(str[i]>'Z')	str[i]-=26;	}
					else			{	if(str[i]>'z')	str[i]-=26;	}
					if(flag2)		{	str[i]=tolower(str[i]);		}
					else			{	str[i]=toupper(str[i]);		}
				}
			}
		}
		cout<<str<<endl;
	}
}
