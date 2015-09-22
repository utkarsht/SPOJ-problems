#include<iostream>
using namespace std;
int main()
{
	double c,sum;
	int i;
	while(1)
	{
		sum=0;
		cin>>c;
		if(c==0.00) break;
	//	if(c<=0.5)  cout<<"1 card(s)\n";
	//	else
		{
			for(i=2; 1 ;i++)
			{
				sum+=1.0/i;
				if(sum>=c)  break;
			}
			cout<<i-1<<" card(s)\n";
		}
	}
}
