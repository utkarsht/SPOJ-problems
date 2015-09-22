#include<iostream>
#include<string>
using namespace std;
class stack
{
    private:
	char p[50];
	int uper;
	public:
		stack(){uper=-1;
		}
	void pop()
	{
		uper--;
	}
	void push(char c)
	{
		p[++uper]=c;
	}
	char top()
	{
		return p[uper] ;
	}
	void show()
	{
	     int i;
	     for(i=uper;i>=0;i--)
	     {
	     	cout<<'|'<<p[i]<<'|'<<endl;
	     }
	}
}stk;
int main()
{
	string s;
	int arr[10000]={0},i,k=-1,rem=0;
	cin>>s;
	for(i=0;i<s.length();i++)
	{
		if(s[i]=='<')
		{
			stk.push('<');
			k++;
		}
		else if(k>=0 && s[i]=='>')
		{
		    stk.pop();
		    k--;  arr[k]=arr[k]+2+arr[k-1];    
			if(arr[k]>rem)  rem=arr[k];
		}
		stk.show();
		cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<" ";
		cout<<endl<<rem<<endl;
	}
	cout<<endl<<rem;
}
