// for this specific series			 f(n) = 2(fib(n+2) - 1) - n

#include<stdio.h>
#include<string.h>
#define s(x) scanf("%d",&x)
#define p(x) printf("%d",x)
#define sl(x) scanf("%lld",&x)
#define pl(x) printf("%lld",x)
#define nl   printf("\n")
#define chk   printf("hello    ")
typedef long long ll;
typedef unsigned long long ull;

ll M;

long long fib(int n)
{
	n++;
    long long fib[2][2]= {{1,1},{1,0}},ret[2][2]= {{1,0},{0,1}},tmp[2][2]= {{0,0},{0,0}};
    int i,j,k;
    while(n)
    {
        if(n&1)
        {
            memset(tmp,0,sizeof tmp);
            for(i=0; i<2; i++) for(j=0; j<2; j++) for(k=0; k<2; k++)
                        tmp[i][j]=( tmp[i][j] % M + ret[i][k] % M * fib[k][j] % M ) % M;
            for(i=0; i<2; i++) for(j=0; j<2; j++) ret[i][j]=tmp[i][j];
        }
        memset(tmp,0,sizeof tmp);
        for(i=0; i<2; i++) for(j=0; j<2; j++) for(k=0; k<2; k++)
                        tmp[i][j]=( tmp[i][j] % M + fib[i][k] % M * fib[k][j] % M ) % M;
        for(i=0; i<2; i++) for(j=0; j<2; j++) fib[i][j]=tmp[i][j];
        n/=2;
    }
    return (ret[0][1]) % M;
}

int main()
{
	int t;
	s(t);
	ll n,sum;
	while(t--)
	{
		sl(n);	 n--;  	sl(M);		//M=100000000;
		sum = ( ( 2*fib(n+2) - 3 ) % M  - n % M )  ;			if(sum<0)    {  sum += M;   sum%=M;  }
		pl(sum);
		nl;
	}

}
