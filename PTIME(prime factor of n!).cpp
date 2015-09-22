#include<bits/stdc++.h>
using namespace std;
#define M 100001
#define T  5000 
int prime[T];
bool arr[M];
void markMultiples(bool arr[], int a, int n)
{
    int i = 2, num;
    while ( (num = i*a) <= n )
    {
        arr[ num-1 ] = 1; 
        ++i;
    }
}
void sieve(int n)
{
	int k = 0;
    if (n >= 2)
    {
        memset(arr, 0, sizeof(arr));
        for (int i=1; i<n; ++i)
        {
            if ( arr[i] == 0 )
            {
                prime[k++] = i+1;
                markMultiples(arr, i+1, n);
            }
        }
    }
}
int main()
{
	int n ,i=0 , save, count;
	sieve(M);
	while(scanf("%d",&n)==1)
	{
		i = 0;
		while(prime[i]<=n)
		{
			if(i!=0)	cout<<" * ";
			save = n;
			count = 0;
			while(n>0)
			{
				count += n/prime[i];
				n /= prime[i];
			}
			n = save;
			cout<<prime[i]<<"^"<<count;
			i++;
		}
		cout<<endl;
	}
}
