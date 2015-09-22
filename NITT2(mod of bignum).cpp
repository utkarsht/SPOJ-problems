#include<bits/stdc++.h>
using namespace std;
int mod(char *b,int a)
{
	int num2 = 0;
	for(int i=0;b[i];i++)
	{
		num2=(num2*10+(int)b[i]-'0')%a;
	}
	return num2;
}
int main()
{
	int A = 252 , B = 525;
	char str[50010];
	int t;
	cin>>t;
	while(t--)
	{
		cin>>str;
		if(mod(str,A)==0)	cout<<"Yes ";		else	cout<<"No ";
		if(mod(str,B)==0)	cout<<"Yes ";		else	cout<<"No ";
		cout<<endl;
	}
}
