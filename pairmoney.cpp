#include<iostream>
using namespace std;
int main()
{
	int t,i,k=0;
	char s[201];
	int con[52]={0};
	cin>>t;
	while(t--)
	{
		k=0;
		cin>>s;
		for(i=0;s[i];i++)
		{
			if(s[i]>='A' && s[i]<='Z')
			con[s[i]-65]++;
			else
			con[s[i]-71]++;
		}
		for(i=0;i<52;i++)
		{  k+=con[i]/2 + con[i]%2;   con[i]=0;  }
		cout<<k<<endl;
    }  
}
		
