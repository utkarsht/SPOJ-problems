#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	int t,flag;
	long n,i;
	string str;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int s[26]={0}, e[26]={0};
		flag=0;
		for(i=0;i<n;i++)
		{
			cin>>str;
			if(str[0]!=str[str.length()-1]){
			s[str[0]-97]++;
			e[str[str.length()-1]-97]++;}
		}
		for(i=0;i<26;i++)
		{
			if(s[i]==e[i])
			flag++;
		}
		if(flag>=24)
		cout<<"Ordering is possible.\n";
		else 
		cout<<"The door cannot be opened.\n";
	}
}
