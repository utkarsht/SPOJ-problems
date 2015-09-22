#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	int t,l;
	string str;
	cin>>t;
	while(t--)
	{
		int flag=0;
		cin>>str;
		l=str.length();
		for(int i=0;i<l/2;i++)
		{
			if(str[i]==str[l-1-i])
			flag++;
			else
			break;
		}
		if(flag==l/2) cout<<"YES\n";
		else cout<<"NO\n";
	}
}
