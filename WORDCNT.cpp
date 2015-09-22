#include<stdio.h>
int main()
{
	int t,i,k,count;
	int max=0;
	char str[20010];
	int a[1001];
	scanf("%d",&t);
	while(t--)
	{
		k=0;
		max=0;
		count=0;
		scanf(" %[^\r\n]",str);
		for(i=0;str[i];i++)
		{
			if(str[i]==' ')
			{  
			  if(str[i-1]!=' ')
			   {a[k++]=count; 
			   count=0;}
			 }
			else count++;
		}
		a[k++]=count;
		count=0;
	//	for(i=0;i<k;i++)
	//	printf("%d\n",a[i]);
		for(i=1;i<k;i++)
		{
			if(a[i]==a[i-1])
			count++;
			else
			{
				if(count>=max)
				max=count+1;
				count=0;
			}
	    }
	    if(count>=max)
				max=count+1;
	    printf("%d\n",max);
	}
}
