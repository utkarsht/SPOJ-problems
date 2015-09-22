#include<stdio.h>
#include<string.h>
#include<math.h>
#define s(x) scanf("%d",&x)
#define p(x) printf("%d",x)
#define sl(x) scanf("%lld",&x)
#define pl(x) printf("%lld",x)
#define gap	printf(" ")
#define nl   printf("\n")
#define chk   printf("hello    ")
#define F(x)	for(int i=0;i<x;i++)

#include<iostream>
using namespace std;
#define r 1234
#define c 5678
int row[r+2];
int column[c+2];
void swap(int &a,int &b)
{
	int t;
	t=a;
	a=b;
	b=t;
}
int main()
{
	char ch;
	int i,j,k=1,rn,cn;
	for(i=1;i<=c;i++)
		column[i] = i;
	for(i=1;i<=r;i++)
	{	row[i] = k;		k += c;		}
	while(cin>>ch)
	{
		if(ch=='R')		
		{
			s(i);	s(j);
			swap(row[i],row[j]);
		}
		else if(ch=='C')		
		{
			s(i);	s(j);	
			swap(column[i],column[j]);
		}		
		else if(ch=='Q')
		{
			s(i);	s(j);
			p(row[i] + column[j] -1 );		nl;
		}
		else
		{
			s(k);
			rn = (k-1)/c ;	rn = rn*c + 1;
			for(i=1;i<=r;i++)	
				if(rn==row[i])	break;
			cn = (k+1-row[i]) ;
			for(j=1;j<=c;j++)
				if(cn==column[j])	break;
			printf("%d %d\n",i,j);
		}
	}

}
