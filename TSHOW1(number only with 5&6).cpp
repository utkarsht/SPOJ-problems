#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int t,j;
	long long num,dif,tn ;
	cin>>t;
	for(j=1;j<=t;j++)
	{
	   	cin>>num;
	    int k=(int)(log10(num+2)/log10(2));
	    dif=num-(pow(2.0,k)-2);
	    if(dif==0)
	    {
	    	k--;
	    	while(k--)
	    	cout<<"6";
	    	cout<<endl;
	    }
	    else
	    {
	    tn=pow(2.0,k);
	    for(int i=0;i<k;i++)
	    {
	       if(dif%(tn)>tn/2 || dif%tn==0)	
	       cout<<"6";
	       else 
	       cout<<"5";
	       tn/=2;
	    }
	    cout<<endl;
	}
    }
}
