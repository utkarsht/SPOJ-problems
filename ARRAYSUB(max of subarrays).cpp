#include<iostream>
#include<set>
#include<cstdio>
using namespace std;
int main()
{
	int n,i,k,p;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	multiset<int,greater<int> > s;
	scanf("%d",&k);
	s.insert(a,a+k);
	for(i=0;i<n-k+1;i++)
	{
		printf("%d ",*(s.begin()));
		p=s.erase(a[i]);
		for(int j=1;j<=p-1;j++)
		s.insert(a[i]);
		s.insert(a[i+k]);
	}
	printf("\n");
}
