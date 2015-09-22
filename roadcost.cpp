#include<iostream>
#include<new>
using namespace std;
int main()
{
	long int t,i,j;
	long int min,k,n;
	cin>>t;
	long int cost=0;
	for(i=0;i<t;i++)
	{
		cost=0;
		cin>>n;
        long int p[n];
		for(j=0;j<n;j++)
		{
			cin>>p[j];
		}
		min=p[0];
		for(j=0;j<n;j++)
		{
			if(min>p[j])
			{
				min=p[j];
			}
		}
		for(j=0;j<n;j++)
		{
		  cost+=min*p[j];  
		}
			cout<<cost-min*min<<endl;
	
	}

}
