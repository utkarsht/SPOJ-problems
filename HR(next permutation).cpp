#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
 int i,t,x,y,k;
 cin>>t;
 while(t--)
 {
    cin>>x>>y>>k;
    vector<char> v(x,'H');
    
    for(i=0;i<y;i++)
    	v.push_back('V');
    if(k==0)	{		for(int i=0;i<v.size();i++) 	cout<<v[i];		cout<<endl;	continue;		}
    for(i=0;i<k;i++)
    {
    	next_permutation(v.begin(),v.end());
    }
    for(int i=0;i<v.size();i++) 	cout<<v[i];		cout<<endl;
 }
}
