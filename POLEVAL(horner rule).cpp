//      template by Utkarsh trivedi
//      problem id-  poleval        			   Based on-		Horner rule polynomial solve
#include<stdio.h>
#define s(x) scanf("%d",&x)
#define p(x) printf("%d",x)
#define sl(x) scanf("%lld",&x)
#define pl(x) printf("%lld",x)
#define nl   printf("\n")

typedef long long ll;

ll solve(int *c,int n, int x)
{
	int i;
	ll b = c[1] + x*c[0] ;
	for(i=2;i<=n;i++)
	{
		b=c[i] + x*b ;
	}
	return b;
}
int main()
{
	int j=0,degree,i,ele;
	int c[1002];	
	int X[102];
	ll value;
	while(true)
	{
		j++;
		
		s(degree);
		if(degree == -1)   break;
		for(i=0;i<=degree;i++)
			s(c[i]);
			
		s(ele);
	
		for(i=0;i<ele;i++)
			s(X[i]);
			
		printf("Case %d:\n",j);
		
		for(i=0;i<ele;i++)
		{
			value=solve(c,degree,X[i]);
			pl(value);		nl;
		}
	}

}
