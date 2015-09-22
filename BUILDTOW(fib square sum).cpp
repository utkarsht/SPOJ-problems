

/*
		// first method ( getting some wrong for big values )  based on fact sum(fib_square) = sum(fib 2*n +/-  1)  +/-  fib(n_sq)  div 2
		if(m%2==0)
		{
			r=fib(m);		r= (r*r) % M ;	
			sum = fib(2*m) - 2 ;		sum=( sum + r ) % M;
			sum=sum/2;
		}
		else
		{
			r=fib(m+1);	 r= (r*r) % M ;	 
			sum = fib(2*m+2) - 2;	sum=( sum - r ) % M;		if(sum<0)   {   	sum=sum+M;    	}
			sum=sum/2;
		}
*/
	
	// used method   is   sum(fib-sq) = fib(n) *  fib(n+1); 
	
#include<stdio.h>
#include<math.h>
#include<string.h>
#define s(x) scanf("%d",&x)
#define p(x) printf("%d",x)
#define sl(x) scanf("%lld",&x)
#define pl(x) printf("%lld",x)
#define nl   printf("\n")
#define chk   printf("hello    ")
typedef long long ll;

ll M=1000000007;

#include<map>
using namespace std;

/*unsigned long long fib(int n)
{
	n++;
    unsigned long long fib[2][2]= {{1,1},{1,0}},ret[2][2]= {{1,0},{0,1}},tmp[2][2]= {{0,0},{0,0}};
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
}*/
//   below one is used function for getting nth fib number          above one is giving wrong for bigger values
map<ll,ll> mp;
ll fib(ll x)
{
	
	if(mp.find(x)!=mp.end())  return mp[x];
	if(x%2==1)
	{
		mp[x]=(  ( fib((x-1)/2) * fib((x-1)/2) ) %M+ (fib((x+1)/2) * fib((x+1)/2))  % M ) % M;
	}
	else
	{
		mp[x]=((ll)2*fib(x/2)*fib((x/2) -1) % M + (fib(x/2) * fib(x/2))%M  ) % M;
	}
	return mp[x];
}
int main()
{
	int t;
	mp[0]=0;     mp[1]=1;   mp[2]=1;	mp[3]=2;
	ll m,sum,sum2;
	s(t);
	
	for(int i=0;i<t;i++)
	{
		sl(m);	m++;             //   m++  for second used function
		sum=fib(m);     sum2=fib(m+1);
	
		sum=( sum*sum2 )% M ; 
		printf("$") ;   pl(sum-1);
		nl;
	}

}
