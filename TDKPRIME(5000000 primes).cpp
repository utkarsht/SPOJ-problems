#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;
#define M  86100000
#define T  5000000
int prime[T];
bool arr[M];
void markMultiples(int a, int n)
{
    int i = 2, num;
    while ( (num = i*a) <= n )
    {
        arr[ num-1 ] = 1; 
        ++i;
    }
}
void sieve(int n,int& k)
{
	markMultiples(2,n);
	prime[k++] = 2;
    if (n >= 2)
    {
        memset(arr, 0, sizeof(arr));
        for (int i=2; i<n; i+=2)
        {
            if ( arr[i] == 0 )
            {
                prime[k++] = i+1;
                markMultiples(i+1, n);
            }
        }
    }
}
int main()
{
	int t,a;
	int k = 0;
	sieve(M,k);		
	cin>>t;
	while(t--)
	{
		cin>>a;		
		cout<<prime[a-1]<<"\n";
	}
}

