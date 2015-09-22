#include<iostream>
#include<string.h>
#include<stack>
using namespace std;
string save[10],st;
void tostr(long n)
{
	long rem;
	stack<string> 	stk;
	string s="";
	while(n>0)
	{
		rem=n%10;
		stk.push(save[rem]);
		n/=10;
	}
	cout<<st;
	while(!stk.empty())
	{
		cout<<stk.top();	stk.pop();
	}
	cout<<endl;
}
int tonum(string str)
{
	if(str=="063")	{	return 	0	;	}
	if(str=="010")	{	return	1	;	}
	if(str=="093")	{	return	2	;	}
	if(str=="079")	{	return	3	;	}
	if(str=="106")	{	return	4	;	}
	if(str=="103")	{	return	5	;	}
	if(str=="119")	{	return	6	;	}
	if(str=="011")	{	return	7	;	}
	if(str=="127")	{	return	8	;	}
	if(str=="107")	{	return	9	;	}
}
int main()
{
	save[0]="063";	save[1]="010";	save[2]="093";	save[3]="079";	save[4]="106";	save[5]="103";	save[6]="119";	save[7]="011";	save[8]="127";	save[9]="107";
	char temp[10];
	long i,l,n1=0,rem=0,n2=0;
	while(1)
	{
		n1=n2=0;
		cin>>st;
		if(st=="BYE")		break;
		l = st.length();
		i=0;
		while(st[i]!='=')
		{
			if(st[i]!='+')
			{
				temp[0]=st[i];		temp[1]=st[i+1];	  temp[2]=st[i+2];		i+=3;		temp[3]='\0';
				rem = tonum(temp);		n2=n2*10+rem;
			}		
			else 
			{	i++;	n1=n2;	n2=0;		}
		}
		n1 = n1+n2;
		tostr(n1);
	}
}
