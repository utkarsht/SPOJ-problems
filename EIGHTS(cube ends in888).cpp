#include<iostream>
using namespace std;
long long term(long long n)
{
	if(n%2==0)
	{
		n=n/2;
		return 5*n-1;
	}
	else
	{
		n=n/2+1;
		return 5*n-4;
	}
}
int main()
{
	int t;
	long long n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		cout<<term(n);
		if(n%2==0)   cout<<"42\n";
		else cout<<"92\n";
	}
}
