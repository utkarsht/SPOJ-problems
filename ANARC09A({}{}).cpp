#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main()
{
	int t,i,j=0;
	while(1)
	{
		j++;
	string s;
	stack<char> a;
	cin>>s;
		if(s[0]=='-')   break;
	for(i=0;i<s.length();i++)
	{
		if(s[i]=='}' && !a.empty())
		{
			if(a.top()=='{')
			a.pop();
			else
			a.push(s[i]);
		}
		else
		a.push(s[i]);
	}
	if(a.size()==0)
	cout<<"Balanced\n";
	else
	cout<<"Not balanced\n";
	i=a.size();
	int count=0;
	while(!a.empty())
	{
		if(a.top()=='{')
		count++;
		else
		break;
		a.pop();
    }
    if(count==0)
    cout<<j<<". "<<i/2<<endl;
    else if(count%2==1)
    cout<<j<<". "<<i/2+1<<endl;
    else
    cout<<j<<". "<<i/2<<endl;
    }
}
