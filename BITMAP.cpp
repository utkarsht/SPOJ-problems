#include<stdio.h>
#include<iostream>
using namespace std;
#define s(x) scanf("%d",&x)
#define p(x) printf("%d ",x)
#define sc(x)  scanf("%c",&x)
#define nl printf("\n")
#define pc(x) printf("%c ",x)
int m,n;
bool ok(int x)
{
	if(x<0)  return 0;
	if(x>=m)  return 0;
	if(x>=n)  return 0;
	return 1;
}
int abs(int x)
{
	return (x>0)?x:-x;
}
int main()
{
	int t,i,j,a,b,c,d,g,min,k;
	s(t);
	while(t--)
	{
		s(n);  s(m);
		char ar[n][m];
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			cin>>ar[i][j];
	}
		
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(ar[i][j]=='1') {     printf("0 ");     }
				else
				{
				min=10000;
				k=1;
				while(1)
				{
				a=i-k;  c=j-k;  b=i+k;  d=j+k;   k++;
				if(!ok(a)  &&  !ok(b)  && !ok(c)  &&  !ok(d))   break;
				if(ok(a))
				{
					//cout<<"oka\n";
				   for(g=c;g<=d;g++)
				   {
				   	 if(ok(g)  && ar[a][g]=='1')
				   	 {
				   	    if(min>(abs(a-i)+abs(g-j)))
				   	    min=abs(a-i)+abs(g-j);
				   	 }
				   }
			    }
			    if(ok(c))
				{
					//cout<<"okc\n";
				   for(g=a;g<=b;g++)
				   {
				   	 if(ok(g)   && ar[g][c]=='1')
				   	 {
				   	    if(min>(abs(g-i)+abs(c-j)))
				   	    min=abs(g-i)+abs(c-j);
				   	 }
				   }
			    }
			    if(ok(b))
				{
					//cout<<"okb\n";
				   for(g=c;g<=d;g++)
				   {
				   	 if(ok(g)  && ar[b][g]=='1')
				   	 {
				   	    if(min>(abs(b-i)+abs(g-j)))
				   	    min=abs(b-i)+abs(g-j);
				   	 }
				   }
			    }
			    if(ok(d))
				{
					//cout<<"okd\n";
				   for(g=a;g<=b;g++)
				   {
				   	 if(ok(g)  && ar[g][d]=='1')
				   	 {
				   	    if(min>(abs(g-i)+abs(d-j)))
				   	    min=abs(g-i)+abs(d-j);
				   	 }
				   }
			    }
			    }
			    p(min);
			    }
		    }
		nl;
	}
	}
}
