#include<iostream>
#include<cstring>
using namespace std;
void addone(char *a)
{
	int l = strlen(a);
	int k;
	if(l%2)
		k = l/2;
	else
		k = l/2 - 1; 
	{
		for(int i=k;i>=0;i--)
		{
			if(a[i]=='9')
				a[i] = '0';
			else
			{	a[i]++;		break;	}
		}
	}
}
int main()
{
	int t,low,high,flag=0;
	bool p;
	char a[1000001];
	cin>>t;
	while(t--)
	{
		flag=0;
		cin>>a;
		int l=strlen(a);
		if(l==1)  					// Case for one digit only
		{   
		    if(a[0]=='9') cout<<"11\n";   
			else   cout<<(char)(a[0]+1)<<endl;  continue;  
	    }		
	    
		for(int i=0;i<l;i++)
		{
			if(a[i]=='9')
				flag++;
		}
		if(flag==l)					// Case for all 9
		{	flag--;  cout<<"1";	while(flag--)	cout<<"0";	cout<<"1\n";	continue;	 }
		
		low = l/2-1;
		if(l%2==0)
			high = l/2;
		else
			high = l/2+1;

		{
			int count = 0;
			while(low>=0  &&  high<=l-1)
			{		
				if(a[low]==a[high])	
					low--,  high++;
				else
					break;
				//count++;
		    } 
		    if(low==-1 && high==l)
				addone(a);
			else if(a[low]<a[high])
				addone(a);
		}
		
		for(int i=0;i<=(l-1)/2;i++)
			cout<<a[i];
		for(int i=l/2-1;i>=0;i--)
		    cout<<a[i];  
		//if(flag) cout<<"1";
		cout<<endl;
	}
}
