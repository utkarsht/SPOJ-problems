#include<iostream>
using namespace std;
class stack
{
  private:
	char plate[100];
  public:
	int index;
	  stack()
	{
		index = -1;
	}
	void push(char p)
	{
		if (index < 101)
			plate[++index] = p;
	}
	char pop()
	{
		return plate[index--];
	}
	bool isemp()
	{
		if (index == -1)
			return 1;
		else
			return 0;
	}
}stk;
int main()
{
	char s[40];
	int i,l,count=0,sum=0,rem=0;
	cin>>s;
	l=strlen(s);
	for(i=0;i<l;i++)
	{
		stk.push(s[i]);
		if(s[i]=='<')   count++;
		if(s[i]=='>' &&  count)
		{
			while(stk.pop()!='<')
			sum++;
			sum++;   count--;
			if(count==0)
			{ if(rem<sum) rem=sum;  sum=0;  }
		}
	}
	if(sum>rem)
	cout<<sum<<endl;
	else cout<<rem<<endl;
}