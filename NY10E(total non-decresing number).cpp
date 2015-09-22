#include<iostream>
using namespace std;
int main()
{
	int t,i,p,num,j;
	long long ans,save[10];
	cin>>t;
	while(t--)
	{
		ans=0;
		cin>>p>>num;
		if(num==1) {    cout<<p<<" 10\n";  continue;    }
		if(num==2) {    cout<<p<<" 55\n";  continue;    }
	    for(i=0;i<10;i++)
	    {
	    	j=10-i;
	    	save[i]=((j)*(j+1))/2;
	    }
	    for(i=0;i<num-3;i++)
	    {
	    	for(j=8;j>=0;j--)
	    	{
	    		save[j]+=save[j+1];
	    	}
	    }
	    for(i=0;i<10;i++)
	    {
	    	ans+=save[i];
	    }
		cout<<p<<" "<<ans<<endl;
	}
}
