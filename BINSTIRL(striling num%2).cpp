#include<iostream>
#include<stdio.h>
#include<string.h>
#include<iomanip>
#define s(x)	scanf("%d",&x)
using namespace std;
#define sz 100
int stirl[sz][sz];
int main()
{
	int t,n,m;
	memset(&stirl,0,sizeof(stirl));
	stirl[0][0] = 1;	
	s(t);
	while(t--)
	{
		s(n);	s(m);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=i;j++)
			{
				stirl[i][j] = j*stirl[i-1][j] + stirl[i-1][j-1];
				cout<<stirl[i][j]%2<<"   ";
			}
			cout<<endl;
		}
	}
}
