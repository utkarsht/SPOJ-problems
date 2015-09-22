#include<iostream>
#include<list>
#include<math.h>
#define sz 100010
using namespace std;
int main()
{
	int t,i,n,a[102],k=1;
	bool num[sz]={0};
	int save[sz]={0};
	for(i=2;i<=100;i++)
	{   
	    a[i]=i*i*i;
	}
	for(i=2;i<=100;i++)
	{
		for(int j=a[i];j<sz;j+=a[i])
		num[j]=1;
	}
	for(int j=1;j<sz;j++)
	{   if(!num[j])  save[j]=k++;   }
	cin>>t;
	for(int j=1;j<=t;j++)
	{
		int count=0;
		cin>>n;
			if(num[n]==1)
		    cout<<"Case "<<j<<": Not Cube Free\n";
		    else
		    {
			cout<<"Case "<<j<<": "<<save[n]<<endl;
		    }	
	}
}


