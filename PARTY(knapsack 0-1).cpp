//      template by Utkarsh trivedi
//      problem id-  party                     Based on-			Knapsack 0-1
#include<stdio.h>
#include<string.h>
#include<algorithm>
#define s(x) scanf("%d",&x)
#define p(x) printf("%d",x)
#define sl(x) scanf("%lld",&x)
#define pl(x) printf("%lld",x)
#define space	printf(" ")
#define nl   printf("\n")
#define chk   printf("hello    ")
typedef long long ll;
typedef unsigned long long ull;

using namespace std;
// for fast input include below one
/*
#define gc getchar_unlocked
void sfast(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}
*/
#define sz1 102
#define sz2 502
int main()
{
	int total,n,i,j;
	int value[sz1] , m[sz1] ;
	int memo[sz1][sz2];
	while(1)
	{
		s(total);
		s(n);
		if(total==0  &&  n==0)		break;
		for(i=0;i<n;i++)	{	s(m[i]);	s(value[i]);    }
		memset( &memo,0,sizeof(memo) );
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=total;j++)
			{
				if(m[i-1]<=j)
					memo[i][j]=max( memo[i-1][j] , ( memo[i-1][j-m[i-1]] + value[i-1] ) );
				else
					memo[i][j]=memo[i-1][j];
			}
		}
		
		i=total;
		while(memo[n][i]==memo[n][i-1])				//  this loop calculates "after optimise solution what is remaining weight"
			i--;									//	i.e. if given weight is 50 and in optimise sol weight is 47 then loop goes 3 times
		p(i);	space;	p(memo[n][total]);  	nl;
	}
}
