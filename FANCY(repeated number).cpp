#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int t;	char str[35];
	ll ans;
	cin>>t;
	while(t--)
	{
		cin>>str;
		int l = strlen(str);
		ans = 1;
		for(int i = l-2 ; i>=0 ; i--)
		{
			if(str[i]==str[i+1])
			{
				ans*=2;
			}
		}
		cout<<ans<<endl;
	}
}
