#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace std;
typedef int Int;
#define sz 500

Int a[sz],pos;
Int ft[sz];

#define dl(x)  ( x & (-x) )
int n;

Int read(int i)
{
	Int sum=0;
	while(i>0)
	{
		sum+=ft[i];
		i-=dl(i);
	}
	return sum;
}
void show()
{
	for(int i=1;i<=pos;i++)
	cout<<i<<"     "<<ft[i]<<endl;
}
Int read2(int i,int j)
{
	return (read(j)-read(i-1));
}
void update(int k,int d)
{
	for (; k <= pos; k += dl(k)) ft[k] += d;
}

int main()
{
	int t,i,k;
	long long count=0;
	cin>>t;
	while(t--)
	{
		count=0;	
		cin>>n;
		if(n==0)   continue;
		for(i=0;i<n;i++)
			{	cin>>a[i]; }
		sort(ft,ft+n);
		pos=-1;
		for(i=0;i<n;i++)
		{
			pos=max(pos,a[i]);
		}
		memset(&ft,0,sz*sizeof(int));
		for(i=n-1;i>=0;i--)
		{
			k=read(a[i]);
			count+=k;
			update(a[i],1);
		}
		cout<<count<<endl;
	}
}
