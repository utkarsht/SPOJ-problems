#include<iostream>
#include<map>
using namespace std;
int main()
{
	int t,k=1;
	string str;
	cin>>t;
	string str1[t];
	map<string,int> m;
	cin>>str;		m[str]=0;		str1[0]=str;		t--;		//  specific for first one
	while(t--)
	{
		cin>>str;
		if(m.find(str)==m.end())
			m[str]=0;
		else
		{
			m[str]++;		if(m[str]==k)	{	str1[k]=str;	k++;	}
		}
	}
	for(int i=0;i<k;i++)
	cout<<i+1<<" "<<str1[i]<<endl;		
}
