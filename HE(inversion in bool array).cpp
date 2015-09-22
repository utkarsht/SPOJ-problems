//		hacker earth 	O and Z task for Oz!

#include <bits/stdc++.h>
#define M 1000006
using namespace std;

int inv(int a[],int n)
{
	int inversion = 0;
	int ct1 = 0;
	for(int i=0;i<n;i++)
	{
		if(a[i] == 1)
		{
			ct1++;
		}
		else
		{
			inversion += ct1;
		}
	}
	return inversion;
}
int main()
{
	int t;
	string str;
	int a[M],b[M];
	cin>>t;
	while(t--)
	{
		cin>>str;
		int l = str.length();
		for(int i=0;i<l;i++)
		{
			if(str[i] == 'O')
				a[i] = 1,
				b[i] = 0;
			else
				a[i] = 0,
				b[i] = 1;
		}
	//	cout<<inv(a,l)<<endl;
	//	cout<< inv(b,l) <<endl;
		cout<<min( inv(a,l) , inv(b,l) )<<endl;
	}
    return 0;
}

