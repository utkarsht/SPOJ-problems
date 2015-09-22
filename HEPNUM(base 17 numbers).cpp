#include<bits/stdc++.h>
using namespace std;
int val(char c)
{
	if(c>='0' && c<='9')
		return c-'0';
	else
		return c-'A'+10;
}
int compare(string& str1,string& str2)
{
	int i,j;
	int l1 = str1.length();	
	int l2 = str2.length();
	for(i=0;i<l1;i++)
		if(str1[i]!='0')
			break;
	for(j=0;j<l2;j++)
		if(str2[j]!='0')
			break;
	if(i==l1 && j==l2)		return 0;
	if(i==l1)	return -1;
	if(j==l2)	return 1;
	if(l1-i > l2-j)
		return 1;
	else if(l1-i < l2-j)
		return -1;	
	while(i!=l1 || j!=l2)
	{
		if(str1[i]==str2[j])
			i++, j++;
		else if(val(str1[i])>val(str2[j]))
			return 1;
		else	
			return -1;
	}
	return 0;
}
int main()
{
	string str1,str2;
	while(1)
	{
		cin>>str1>>str2;
		if(str1=="*")	break;
		if(compare(str1,str2)==1)
			cout<<">\n";
		else if(compare(str1,str2)==-1)
			cout<<"<\n";
		else
			cout<<"=\n";
	}
}
