#include<iostream>
using namespace std;
int main()
{
	int t;
	long m,n;
	cin>>t;
	while(t--)
	{
		cin>>m>>n;
		if(n>=m)
		{
			if(m%2==0)
			cout<<"L\n";
			else
			cout<<"R\n";
		}
		else
		{
			if(n%2==0)
			cout<<"U\n";
			else
			cout<<"D\n";
		}
	}
}
