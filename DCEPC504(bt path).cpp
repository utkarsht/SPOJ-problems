# include<iostream>
#include<math.h>
using namespace std;
typedef long long ll;
void rev(char &a)
{
	if(a=='R')	a = 'B';
	else		a = 'R';
}
int main()
{
	ll n,r,c;
	char m = 'R';
	cin>>n;

	for(int i=0;i<n;i++)
	{
		m = 'R';
		cin>>r>>c;
		c++;
		ll p = pow(2,r);
		while(p>=1)
		{
			p/=2;
		//	cout<<m<<endl;
			if(c<=p)
			{
			    rev(m);
			}
			else
			c-=p;
		//	cout<<m<<endl;
		}
		if(m=='R')	cout<<"red"<<endl;
		else		cout<<"blue"<<endl;
	}
}
