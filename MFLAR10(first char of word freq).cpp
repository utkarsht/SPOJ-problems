#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
int main()
{
	while(1)
	{
		int flag=0;
		char str[1000],c;
		gets(str);
		if(strcmp(str,"*")==0)   break;
		for(int i=0 ; str[i] ; i++)
		str[i]=	toupper(str[i]);
		for(int i=0 ; str[i] ; i++)
		{
			c=str[0];
			if(str[i]==' ')
			{  if(str[i+1]!=c) { cout<<"N\n";   flag=1;  break;    }   }
		}
		if(flag==0)   cout<<"Y\n";
	}
}
