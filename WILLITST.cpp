#include<iostream>
using namespace std;
int main()
{
	long long n;
	cin>>n;
	bool flag=0;
	while(n>1)
	{
		if(n%2==0)
		n=n/2;
		else
		n=3*n+3;
		if(n%3==0) {  cout<<"NIE";  flag=1;  break;  }
	}
	if(!flag)
	cout<<"TAK";
}
/*
Another method   
A number that is of the form 2^n would terminate.
checking of 2^n is very good see if statement
#include<stdio.h>
int main()
{
    long long int t;
    scanf("%lld",&t);
    if((t&(t-1))==0)    //checks for 2^n
        printf("TAK\n");
    else
        printf("NIE\n");
    return 0;
}
*/
