#include<stdio.h>
#define s(x) scanf("%d",&x)
#define p(x) printf("%d",x)
#define sl(x) scanf("%lld",&x)
#define pl(x) printf("%lld",x)
#define gap	printf(" ")
#define nl   printf("\n")
#define F(x)	for(int i=0;i<x;i++)

#include<iostream>
#include<string>
using namespace std;

#define sz 101

int hash(string str)
{
	int l=str.length();
	long  h=0;
	for(int i=0;i<l;i++)
	{
		h = h+str[i]*(i+1);
		h = h%sz;
	}
	h = h*19;	
	return h%sz;
}

int main()
{
	int t,n,l,key,j;
	s(t);
	string str,p,q;
	while(t--)
	{
		int count=0;
		string HashT[sz];
		F(101)	{	HashT[i] = "";	}
		s(n);
		F(n)
		{
			cin>>str;
			p = str.substr(4);
		    q = str.substr(0,3);
		//	cout<<q<<endl;
			if(q=="ADD")
			{
				key = hash(p);
				j=1;
				while(HashT[key]!="" && j<=19)
				{
					if(HashT[key]==p)	j=20;
					key = key + j*j +23*j ;
					key = key%sz;
					j++;
				}
				if(j<20)	{	HashT[key] = p;			count++;	}
			}
			else if(q=="DEL")
			{
				key = hash(p);
				j=1;
				while(HashT[key]!=p && j<=19)
				{
					key = key + j*j +23*j ;
					key = key%sz;
					j++;
				}	
				if(j<20)	{	HashT[key] = "";		count--;	}
			}
		}
		p(count);	nl;
		F(101)
		{
			if(HashT[i]!="")	cout<<i<<":"<<HashT[i]<<endl;
		}
	}

}
