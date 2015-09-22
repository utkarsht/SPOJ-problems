#include<bits/stdc++.h>
using namespace std;
	bool visit[102];
int sch(int *a,int beg,int end,int item)
{
	/*int	mid=(beg+end)/2;                       
	while(beg<=end && a[mid]!=item)      
	{
		if(a[mid]<item)
			beg=mid+1;
		else
			end=mid-1;
		mid=(beg+end)/2;
	}
	if(a[mid]==item)
		return mid;
	else 
		return -1;*/
    int save = -1;
	for(int i=beg;i<=end;i++)
	{
		if(a[i]==item && !visit[i])
		{	save = i;	break;	}
	}
	return save;
}

int main()
{
	int t,n,ct,k;
    int  a[102];

	cin>>t;
	while(t--)
	{
		ct=0;
		cin>>n;
		memset(&visit,0,sizeof(visit));
		for(int i=0;i<n;i++)
			cin>>a[i];
		sort(a,a+n);
		for(int i=0;i<n;i++)
		{
			if(!visit[i])
			{
				visit[i] = 1;
				k = sch(a,i,n-1,2*a[i]);
				if(k!=-1)
				{  ct++;  	visit[k]=1; }
			}
		}
		cout<<ct<<endl;
	}
}
