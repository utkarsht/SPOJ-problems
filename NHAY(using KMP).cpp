#include<stdio.h>
#include<string.h>
int m,n;
int* build_prefun(char* p,int *pi)
{
	int k,i;
	pi[0]=0;    k=-1;
	for(i=1;i<m;i++)
	{
		while(k>=0 and p[k+1]!=p[i])
		 {   k=pi[k];   if(k==0)  k=-1;  }
		if(p[k+1]==p[i])
		  k++;
		pi[i]=k+1;
	}
	return pi;
}
int kmp(char* t,char* p,int *pi)
{
	int count=0,k=-1;
	for(int i=0;i<n;i++)
	{
		while(k>=0 and p[k+1]!=t[i])
		{   k=pi[k];    if(k==0) {  k=-1;  }   }
		if(p[k+1]==t[i])
		{   k++;   }
		if(k==m-1)
		{   count++;  printf("%d\n",i-m+1);      k=pi[k];  k--;  }
	}
	return count;
}
int main()
{
  int i;
  while (scanf("%d",&m)) {
    int pi[m];
    char pattern[1000000];
	char text[1000000];
    scanf("%s",pattern);
    build_prefun(pattern,pi);  
    scanf("%s",text);
    n=strlen(text);
   // printf("%s\n",pattern);
   // printf("%s\n",text);
    if(n<m)  {    printf("\n");   continue;   }
    int count=kmp(text,pattern,pi);
    if(!count)   printf("\n");
  }
  return 0;
}
