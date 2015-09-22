#include<iostream>
using namespace std;
int main()
{
	int a,b,c;
	while(1)
	{
		cin>>a>>b>>c;
		if(!a && !b && !c)   break;
		if(b-a==c-b)
		cout<<"AP "<<2*c-b<<endl;
		else if(b/a == c/b)
		cout<<"GP "<<c*c/b<<endl;
	}
}

