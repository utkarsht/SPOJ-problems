#include<iostream>
#include<string.h>
#include<vector>
#define sz 2002
using namespace std;
int ans[2][sz];
int lcs(vector<int> &v1, vector<int> &v2)
{
	int i,j;
	for(i=1;i<=v1.size();i++)
	{
		for(j=1;j<=v2.size();j++)
		{
			if(v1[i-1]==v2[j-1])	ans[i%2][j] = 1+ans[(i-1)%2][j-1];
			else
			{
				ans[i%2][j] = max(ans[(i-1)%2][j],ans[i%2][j-1]);
			}
		}
	}
	return ans[(i-1)%2][j-1];
}
int main()
{
	int t,a,j;
	cin>>t;
	while(t--)
	{
		int count = -2147483647;
		vector<int> v[sz];
		vector<int> v1;
		int i=0;
		while(1)
		{
			cin>>a;		if(!a)	break;
			v1.push_back(a);
		}
		while(1)
		{
			cin>>a;	    if(!a)	break;
			while(1)
			{
				v[i].push_back(a);
				cin>>a;		if(!a)	break;
			}
			i++;
		}
		for(j=0;j<i;j++)
		{
			memset(&ans,0,sizeof(ans));
			count = max(count , lcs(v1,v[j]));
		}
		cout<<count<<endl;
	}
}
