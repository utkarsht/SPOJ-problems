#include<stdio.h>
#define scanint(t)  scanf("%d",&t)
int main()
{
	int t,n,max,k,i;
	scanint(t);
	while(t--)
	{
		scanint(n);
		int a[n],b[n];
		max=0;
		for(i=0;i<n;i++)
		{
			scanint(a[i]);  scanint(b[i]);
			if(max<a[i])
			{  max=a[i];   k=i;  }
		}
	//	printf("%d       %d\n",max,k+1);
		for(i=0;i<n;i++)
		{
			if(b[i]>max  &&   i!=k )
			break;
		}
		if(i!=n)     printf("-1\n");
		else printf("%d\n",k+1);
	}
}
