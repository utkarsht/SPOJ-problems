#include<iostream>
using namespace std;
int count(int n)
{
	int c = 0;
	while(n!=1)
	{
		if(n%2)
			n=3*n+1;
		else
			n/=2;
		c++;
	}
	return c;
}
int main()
{
	int i,j,m=-1;
	while(cin>>i>>j)
	{
		m = -1;
		if(i<j)		
		for(int k=i;k<=j;k++)
		{
			m = max(m,count(k));
		}
		else
		for(int k=j;k<=i;k++)
		{
			m = max(m,count(k));
		}
		cout<<i<<" "<<j<<" "<<m+1<<endl;
	}	
}                	
