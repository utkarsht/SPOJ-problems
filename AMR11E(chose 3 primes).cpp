#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
#define M 10000
int prime[M];
int arr[M];
void markMultiples(int arr[], int a, int n)
{
    int i = 2, num;
    while ( (num = i*a) <= n )
    {
        arr[ num-1 ]++; 
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
	int i,j,k;
	int z = 0;	int n;
	sieve(3000);
	int save[2000];
	for(i=0;i<M;i++)
	{
		if(arr[i]>=3)
			save[z++] = i+1;
	}
//	cout<<z<<endl;
//	sort(save,save+z);
//	for(i=0;i<z;i++)
//		cout<<save[i]<<endl;
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		cout<<save[n-1]<<endl;
	}
}
