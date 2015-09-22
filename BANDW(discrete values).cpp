#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	string a,b;
	bool flag;
	while(1)
	{
		flag=1;
		int count=0;
		cin>>a>>b;
		if(a=="*" && b=="*")	break;
		int l=a.length();
		for(int i=0;i<l;i++)
		{
		//		{	cout<<a[i]<<" "<<b[i]<<"   "<<flag<<"  "<<count<<endl;	}
			if(a[i]!=b[i] && flag)
			{  count++;   flag=0;	}
			else if(a[i]==b[i])
			flag=1;	
		}
		cout<<count<<endl;
	}
}
