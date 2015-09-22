#include<iostream>
using namespace std;
int max(int a,int b)
{
	if(a>=b)  return a;
	else return b;
}
int max(int a,int b,int c)
{
	if(a>b && a>c)   return a;
	if(b>a && b>c)   return b;
	if(c>a && c>b)   return c;
	if(a==b && a>c)   return a;
	if(b==c && b>a)   return b;
	if(a==c && a>b)   return a;
}
int main()
{
	int t,i,j,r,c,maxi;
	cin>>t;
	while(t--)
	{
		cin>>r>>c;  		 int a[r][c];
		int count[r][c];
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			count[i][j]=0;
		}
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			cin>>a[i][j];
		}  
		for(i=0;i<c;i++)
		count[r-1][i]=a[r-1][i];
		for(i=r-2;i>=0;i--)
		{
			for(j=0;j<c;j++)
			{
				
				if(j==0)
			 {
			    count[i][j]=a[i][j]+max(count[i+1][j],count[i+1][j+1]);
			}
				if(j==c-1)								
				count[i][j]=a[i][j]+max(count[i+1][j],count[i+1][j-1]);
				else
				count[i][j]=a[i][j]+max(count[i+1][j],count[i+1][j-1],count[i+1][j+1]);
			}
		}
		maxi=count[0][0];
		for(i=0;i<c;i++)
		{
			if(count[0][i]>maxi)
			maxi=count[0][i];
		}
		cout<<maxi<<endl;
	}
}
