#include<iostream>
#include<set>
using namespace std;
int main()
{
	int i;
	set<int> save;
	int aray[500002];
	int sz=500000;
	aray[0]=0;
	save.insert(0);
	int a=0,b;
	for(i=1;i<=sz;i++)
	{
		b=a-i;
		if(b<0) 
			b=a+i;
		else if( save.find(b) != save.end())
		    b=a+i;
		save.insert(b);
		a=b;
		aray[i]=a;
		//cout<<aray[i]<<"  ";
	}
	while(1)
	{
		int n;
		cin>>n;
		if(n==-1)   break;
		cout<<aray[n]<<endl;
	}
}
