#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
int main()
{
	ll series , n;
	int pos;
	int a[] = {1,4,9,16,25,36,49,64,81};
	while(cin>>n)
	{
		series = n/9;
		pos = n%9;
		if(pos==0)	{	pos = 9;	series--;	}
		if(series!=0)
			cout<<(series*81+a[pos-1])<<endl;
		else
			cout<<a[pos-1]<<endl;
	}
}
