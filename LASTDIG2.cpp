#include<iostream>
#include<vector>
using namespace std;
int main()
{
	string a;
	long long b;
	int t,i;
	int save,ans;
	cin>>t;
	while(t--)
	{
		cin>>a;
		cin>>b;
		if(a=="0" && b==0) {  cout<<"0\n";   continue;  }
		if(b==0)   {  cout<<"1\n";   continue;  }
		vector<bool> v;
		while(b>0)
		{
			v.push_back(b%2);
			b/=2;
		}
		
		ans=1;   save=(int)a[a.length()-1]-'0';
		for(i=0;i<v.size();i++)
		{
			if(v[i])
			{
				ans=(ans%10 * save%10) % 10;
			}
			save=(save*save)%10;
		}
		cout<<ans<<endl;
	}

}
