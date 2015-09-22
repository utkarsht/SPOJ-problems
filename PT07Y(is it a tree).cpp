#include<iostream>
#include<list>
#include<vector>
#include<set>
using namespace std;
int main()
{
	int a,b,m,n;
	set<int>  s;
	set<int>:: iterator p1,p2;
	cin>>n>>m;
	bool flag=0;
	cin>>a>>b;
	  s.insert(a);   s.insert(b);
	for(int i=1;i<m;i++)
	{
		cin>>a>>b;
		p1=s.find(a);  p2=s.find(b);
		if(p1!=s.end()  &&  p2!=s.end())   flag=1;
		else
		{   s.insert(a);   s.insert(b);   }
	}
	if(flag==1 || s.size()!=n) cout<<"NO\n";
	else 
	cout<<"YES\n";
}
