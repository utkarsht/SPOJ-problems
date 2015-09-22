#include<iostream>
using namespace std;
int value(char c)
{
	if(c=='m')    return 1000;
	if(c=='c')    return 100;
	if(c=='x')    return 10;
	if(c=='i')    return 1;
}
char character(int x)
{
	return (char)(x+'0');
}
int mcxi(string str)
{
	int sum=0;
	for(int i=0;i<str.length();i++)
	{
		if(str[i]=='m' || str[i]=='c' || str[i]=='x' || str[i]=='i')
		{
			if(str[i-1]>='0' && str[i-1]<='9')
			sum+=(str[i-1]-'0') * value(str[i]);
			else
			sum+=value(str[i]);
		}
	}
	return sum;
}
string revmcxi(int num)
{
	int d[4]={0},k=0;
	char p[4]={'i','x','c','m'};
	string s="";
	while(num>0)
	{
		d[k++]=num%10;
		num=num/10;
	}
	//cout<<d[3]<<d[2]<<d[1]<<d[0]<<endl;
	for(int i=3;i>=0;i--)
	{
		if(d[i]!=0)
		{
			if(d[i]==1)
		    s+=p[i];
		    else
		    {
		    s+=character(d[i]) ;
		    s+=p[i];
		    }
		}
	}
	return s;
}
int main()
{
	int t,a;
	string str1,str2;
	cin>>t;
	while(t--)
	{
		cin>>str1>>str2;
		str1+="0";   str2+='0';
		a=mcxi(str1) + mcxi(str2);
		//cout<<a<<endl;
		cout<<revmcxi(a)<<endl;
	}
}
