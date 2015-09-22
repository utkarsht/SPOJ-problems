//  Refer:  http://www.quora.com/Can-somebody-explain-solution-to-SPOJ-com-Problem-M3TILE

#include<iostream>
#define M 40
using namespace std;
int f[M],g[M];
int F(int n)
{
	if(n<0)
		return 0;
	if(n==0)					// Base case carefully check if n=0 still 1 arrangement possible - nothing
		return 1;
	return f[n];
}
int G(int n)
{
	if(n<=0)
		return 0;
	return g[n];
}
int main()
{
	int n;
	while(1)
	{
		cin>>n;
		if(n==-1)	break;
		for(int i=1;i<=n;i++)
		{
			f[i] = 3*F(i-2) + 2*G(i-3);					// check these two relation by making diagram
			g[i] = F(i-1) + G(i-2);
		}		
		cout<<F(n)<<endl;
	}
}
