#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll sod(ll n)
{
	ll sum = 0 ;
	while(n>0)
	{
		sum += n%10;
		n/=10;
	}
	return sum;
}
int firstn(int n)
{
	return (n*(n+1))/2;
}
ll digsum(ll n,int d)
{
	if(d==1)		return firstn(n);
	d--;
	return  ( d*(45*n*pow(10,d-1)) + firstn(n-1)*pow(10,d) + n );			// return sum upto x000000   d times zero as upto  2000 , 30 
}
ll sumofdigit(ll n)
{
	ll sum = 0 ,pre  ;
	int pos = log10(n) + 1;
	for(int i=pos;i>=1;i--)
	{
		sum += digsum(n%10,pos-i+1);				//	as 234 = 200 + 30 + 4 	sum
		pre = sod(n/10)*(n%10)*pow(10,(pos-i));		//	extra Multiple  like in above with 30 we need to count 2 30 times and 4 3 times  	
		sum+=pre;
		n/=10;
	}
	return sum;
}
ll brute(ll n)
{
	ll sum = 0;
	for(ll i=1;i<=n;i++)
	{
		sum += sod(i);
	}
	return sum;
}
int main()
{
	ll a, b;
	while(1)
	{
		cin>>a>>b;
		if(a==-1  &&  b==-1)		break;
	//	cout<<brute(a) <<"   ";
		cout<<sumofdigit(b) - sumofdigit(a) + sod(a) <<endl;
	}
}
