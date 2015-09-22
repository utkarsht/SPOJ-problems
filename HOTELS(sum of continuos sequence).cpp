//  2 pointer method question

#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n,m,i,start=0;
	cin>>n>>m;
	int a[n];
	for(i=0;i<n;i++)
	cin>>a[i];
	for(i=0;i<n;i++)
	if(a[i]<m)  break;
	if(i==n)   printf("0\n");
	else
	{
	int cursum=a[i];
	int max=a[i];
	start=i;
	i++;
	//cout<<i<<endl;
	for(;i<n;i++)
	{
		cursum=cursum+a[i];
		while(cursum>m && start<i)
		{
			cursum=cursum-a[start];
			start++;
		}
		if(cursum>max  &&  cursum<=m)
		max=cursum;	
	//	cout<<cursum<<endl;
	}
	printf("%d\n",max);
    }
}
