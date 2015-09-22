#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#define s(x) scanf("%d",&x)
#define p(x) printf("%d",x)
#define sl(x) scanf("%lld",&x)
#define pl(x) printf("%lld",x)
#define gap	printf(" ")
#define nl   printf("\n")
using namespace std;
int main()
{
    int t,i,n,k;
    bool flag=0;
    int max,premax,sum,presum,sumsave;
    s(t);
    while(t--)
    {
        sum=presum=0;
        flag=0;
        max=premax=0;
        s(n);  s(k);
        int a[n];
        for(i=0;i<n;i++)
        {
            s(a[i]);
        }
        int low=0;
        for(i=0;i<n;i++)
        {
            sum+=a[i];
            premax++;
            while(sum>k)
            {
                sum-=a[low++];
                premax--;
            }
            if(max<=premax)
            {
                if(max==premax)     {   presum=min(presum,sum);    }
                else    {   max=premax;     presum=sum;  }
            }
        }
        printf("%d %d\n",presum,max);
    }
}
