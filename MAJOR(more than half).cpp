#include<stdio.h>
int main(){
	int t,n,i;
	scanf("%d",&t);
	while(t--)
	{
		int k,flag=1,j;
		scanf("%d",&n);
		int a[n];
		int m[2002]={0};
	    for(i=0;i<n;i++)
	    {
	    	scanf("%d",&k);
	    	k=k+1000;
	    	if(flag)
	    	{
	    	m[k]++;
	    	if(m[k]>n/2)  { flag=0;   j=k;   }
	        }
	    }
	    if(flag==0)   printf("YES %d\n",j-1000);
	    else printf("NO\n");
	}
	return 0;
}
