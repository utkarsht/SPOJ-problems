#include<iostream>
#include<math.h>
#include<vector>
#define sz 5
using namespace std;
typedef long long ll;
ll remove5pow(ll num,int &pow)
{
	ll n=5;   pow=1;
	while(num>n)
	{
		num-=n;
		n*=5;
		pow++;
	}
	return num-1;
}
int main()
{
	long long num;
	int pow;
	int t;
	char c[5]={'m','a','n','k','u'};
	cin>>t;
	while(t--)
	{
		vector<char> v;
		cin>>num;
		num=remove5pow(num,pow);
		while(num>0)
		{
			v.insert(v.begin(),c[num%sz]);
			num/=5;
		}
		while(v.size()<pow)
		{
			v.insert(v.begin(),c[0]);
		}
		for(int i=0;i<v.size();i++)
		cout<<v[i];
		cout<<endl;
	}
}
