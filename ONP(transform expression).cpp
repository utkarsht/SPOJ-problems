#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main()
{
	stack<char> s;
    int t,i;
    string str;
    cin>>t;
    while(t--)
    {
    	cin>>str;
    	for(i=0;i<str.length();i++)
    	{
    		if(str[i]>='a' && str[i]<='z')
    		cout<<str[i];
    		else
    		{
    			if(str[i]==')')
    			{
    				while(s.top()!='(')
    				{  cout<<s.top();     s.pop();  }
    				s.pop();
    			}
    			else 
    			s.push(str[i]);
    		}
    	}
    	cout<<endl;
    }
}
