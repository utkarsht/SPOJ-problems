#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int t,k,g,i,h;
	cin>>t;
	while(t--)
	{
		cin>>g;
		k=(sqrt(1+8*g)-1)/2;
		for(i=k+2;i>=1;i--)
		{
			if(g>(i*(i+1))/2  &&  g<=((i+1)*(i+2))/2)
			break;
		}
		i++;
		h=g-(i*(i-1))/2;
		if(i%2==0)
		{
			cout<<"TERM "<<g<<" IS "<<h<<"/"<<i+1-h<<endl;
		}
		else
		{
			cout<<"TERM "<<g<<" IS "<<i+1-h<<"/"<<h<<endl;
		}
		
	}
}
