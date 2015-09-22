#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
int check(string & s)
{
	int flag=0,more=0;
	int zir=0,zor=0;
	if(s[0]>=65  && s[0]<=90)  return 0;
	if(s[0]=='_')     return 0;
	for(int i=0;i<s.length()-1;i++)
	{
		if(s[i]=='_' && s[i+1]>='0'  && s[i+1]<='9')
		return 3;
	}
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='_')
			zir=1;
		if(s[i]>='A' && s[i]<='Z')
			zor=1;
	}
	if(zir && zor)	return 3;
	for(int i=0;i<s.length();i++)
	{
		if (s[i]>=65 && s[i]<=90)
		{
			more=1;
		}
		if(s[i]=='_')
		{
			if(more==1) 
			return 0;
			if ((s[i+1]>=65 && s[i+1]<=90)  ||  i+1==s.length() ||  s[i+1]=='_')
			return 0;
		    more=2;
		    flag=1;
		}
		if(more==2)
		{
			if (s[i]>=65 && s[i]<=90)
			return 0;
			flag=1;
		}
		if(s[i]>=97 && s[i]<=122)
		{
			if(more!=2)
			flag=3;
		}
		
	}
	if(flag==3)           return 2;
	if(flag==1)           return 1;
	else if(flag==2)      return 2;
}
void converttojava(string& s)
{
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='_')
		{
			s[i+1]-=32;
		}
	}
	for(int i=0;i<s.length();i++)
	{
		if(s[i]!='_')
		cout<<s[i];
	}
	cout<<endl;
}
void converttoc(string& s)
{
	for(int i=0;i<s.length();i++)
	{
		if (s[i]>=65 && s[i]<=90)
		{
			cout<<'_';
			cout<<(char)(s[i]+32);
		}
		else
		cout<<s[i];
    }
    cout<<endl;
}
int main()
{
	string str;
	while(cin>>str)
	{
		if(check(str)==1)           		 // 1 for java
		{
			converttojava(str);
		}
		else if(check(str)==2)    		    // 2 for c++
		{
			converttoc(str);
		}
		else
		cout<<"Error!\n";
	}
}
