//   problem  6  number steps  NSTEPS
#include<iostream>
using namespace std;
int main()
{
	int t,a,b;
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		if(a==b  ||  a-b==2)
		{
			if(a==b)
			{
				if(a%2==0)
				cout<<2*a<<endl;
				else 
				cout<<2*a-1<<endl;
			}
			else
			{
				if(a%2==0)
				cout<<2*a-2<<endl;
				else
				cout<<2*a-3<<endl;
			}
		}
		else 
		cout<<"No Number\n";
	}
}
