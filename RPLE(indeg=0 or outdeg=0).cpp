#include<stdio.h>
#include<math.h>
#include<string.h>
#include<set>
#define s(x) scanf("%d",&x)
#define p(x) printf("%d",x)
#define sz 1004
using namespace std;
int main()
{
	int t,a,b,n,r,flag,i;
	s(t);	int indeg[sz];	int outdeg[sz];
	for(int j=1;j<=t;j++)
	{
		memset(&indeg,0,sizeof(indeg));
		memset(&outdeg,0,sizeof(outdeg));
		s(n);	s(r);
		for(i=0;i<r;i++)
		{
			s(a);	s(b);
			outdeg[a]++;	indeg[b]++;
		}
		flag=0;
		for(i=0;i<n;i++)
		{
		//	printf("%d  : in- %d  out- %d \n",i,indeg[i],outdeg[i]);
			if(  indeg[i]==0 || outdeg[i]==0 )
			flag++;
		}
		if(flag==n)
		printf("Scenario #%d: spying\n",j);
		else
		printf("Scenario #%d: spied\n",j);
	}	
}
