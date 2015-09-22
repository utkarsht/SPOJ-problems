#include<iostream>
#include<cmath>
#include<stdlib.h>
using namespace std;
int main()
{
	int total,n,i,a[10],count[10]={0},flag=0,del=0;
	cin>>total>>n;
	for(i=0;i<n;i++)
	cin>>a[i];
	i=0;
	int m=45;
    while(m--)
    {
    	total-=a[i];
    	count[i]++;
    	if(total<0) {  count[i]--;   total+=a[i];
    	 i++;}
    /*	if(count[i]==1 &&  total<0)
    	{
    		cout<<"NO\n";
    		exit(1);
    	}*/
    //	cout<<total<<"   ";
    	if(total==0)
    	break;
    	if(i>=n)  {  	cout<<"NO\n";
    del=-1;  break;
    }
    }
    if(del!=-1)  {
    
    for(i=1;i<n;i++)
    {
    	if(count[0]>=count[i])
    	flag++;
    }
    if(flag==n-1)  cout<<"YES\n";
    else cout<<"NO\n";
}
}
