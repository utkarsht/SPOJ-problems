#include<iostream>
#include<string.h>
#include<cstdio>
using namespace std;
long long solve(long long inter,long long a,char c )
{
	if(c=='+')   return inter+a;
	if(c=='-')   return inter-a;
	if(c=='*')   return inter*a;
	if(c=='/')   return inter/a;
}
int main()
{
	long long t;
	long long a,inter,b,result;
	char str[10000];
	cin>>t;
	while(t--)
	{
		long long i=0;
		bool flag=0;
		char oprt;
		a=0;
		while(1)
		{
			cin>>str[i];
			if(str[i]=='=')  {  str[i+1]='\0';     break;  }
			i++;
		}
	//	cout<<str<<endl;
		for(i=0;str[i];i++)
		{
			if(str[i]>='0' && str[i]<='9')
			{
			b=str[i]-'0';
			a=10*a+b;
			//cout<<a<<"     "<<b<<endl;
		    }
			else if(str[i]=='+'||str[i]=='='||str[i]=='-'||str[i]=='*'||str[i]=='/')
			{
				if(flag==0)
				{
				inter=a;     a=0;      flag=1;     oprt=str[i];
			    }
			    else
			    {
			    	inter=solve(inter,a,oprt);
			    	a=0;
			    	oprt=str[i];
			    }
			}
		}
		cout<<inter<<endl;
	}
}
