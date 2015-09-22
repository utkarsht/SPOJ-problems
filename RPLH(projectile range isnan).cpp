#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;
int main()
{
	int t;
	int r,u;
	double angle , g = 9.806 , pi = 2*acos(0.0);
	cin>>t;
	for(int j=1;j<=t;j++)
	{
		cin>>r>>u;
		angle = (r*g)/(u*u);
		angle = asin(angle);
		angle = (double)(angle*90)/pi;
		if(isnan(angle)==1)	printf("Scenario #%d: -1\n",j);
		else				printf("Scenario #%d: %.2f\n",j,angle);
	}
}
