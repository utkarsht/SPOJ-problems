#include<iostream>
using namespace std;
unsigned long long comb(long long n, long long r)
{
	if(n-r<r)  r=n-r;
	unsigned long long pro=1;
	for(int i=0;i<r;i++)
	{
		pro = pro*(n)/(i+1);
		n--;
	}
	return pro;
}
int main()
{
	int t;
	long long n,k;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		if(k<0 || k>n)   cout<<"0\n";
		if(n==k)  cout<<"1\n";
		else
		{
		cout<<comb(n-1,k-1);
		cout<<endl;
	    }
	}
}

