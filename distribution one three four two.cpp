#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	int t,k,l,m,n,i,count,flag;
	string s;
	t=1;
	while(t--)
	{
		k=l=m=0;
		flag=1;
		count=1;
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>s;
			if(s=="1/2")           
			k++;                   // k- one two
			else if(s=="1/4")
			l++;                   // l- one four
			else
			m++;                   // m- three four
		}
		count+=k/2;                  // for 1/2 + 1/2
		count+=(l>=m)?m:l;      // for 3/4 + 1/4
		if(k%2==0)
		flag=0;
		if(l>m)
		{  
			count=count+(l-m)/4;      //for extra 1/4
		    if(flag  &&  (l-m)%4==3)
			{
				count=count+2;
			}      
			else if(flag)
			count++;
			else if((l-m)%4>0)
			count++;
		}
		else if(m>l)
		{
			count+=(m-l);
			if(flag)
			count++;
		}
		else if(flag)
		count++;
		cout<<count<<endl;
		
	}
}
