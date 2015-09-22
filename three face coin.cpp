#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int t,n,i;
	string s;
	cin>>t;
	while(t--)
	{
		int count[8]={0};
		cin>>n;
		cin>>s;
		for(i=0;i<38;i++)
		{
			if(s[i]=='T' && s[i+1]=='T' && s[i+2]=='T')
			count[0]++;
			if(s[i]=='T' && s[i+1]=='T' && s[i+2]=='H')
			count[1]++;
			if(s[i]=='T' && s[i+1]=='H' && s[i+2]=='T')
			count[2]++;
			if(s[i]=='T' && s[i+1]=='H' && s[i+2]=='H')
			count[3]++;
			if(s[i]=='H' && s[i+1]=='T' && s[i+2]=='T')
			count[4]++;
			if(s[i]=='H' && s[i+1]=='T' && s[i+2]=='H')
			count[5]++;
			if(s[i]=='H' && s[i+1]=='H' && s[i+2]=='T')
			count[6]++;
			if(s[i]=='H' && s[i+1]=='H' && s[i+2]=='H')
			count[7]++;
		}
		cout<<n<<" ";
		for(i=0;i<8;i++)
		cout<<count[i]<<" ";
		cout<<endl;
	}
}
