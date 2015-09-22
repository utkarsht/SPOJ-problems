#include<stdio.h>
#include<math.h>
#define s(x) scanf("%ld",&x)
#define p(x) printf("%ld",x)
#define nl   printf("\n")
typedef long long ll;
int max(int x,int y)
{
	return (x>y)?x:y;
}
struct pair
{
	int x;
	int y;
};
int main()
{
	ll t,n,a,b,c,d,x,y,i,x1,y1,iter;
	ll mat[2][2];
	s(t);
	while(t--)
	{
		s(n);
		s(a);	s(b);	s(c);	s(d);
		s(x);	s(y);	
		x1=x;	y1=y;
		if(x==1 && y==1)	{	p(n);	nl;	  continue;	}
		mat[0][0]=a*n;	mat[0][1]=b*n;	mat[1][0]=c*n;	mat[1][1]=d*n;
		iter = ceil(log2(max(x,y))) ;
		pair p[iter-1];
		for(i=iter-2;i>=0;i--)
		{
			if(x%2==0)	{	  x=x>>1; 	}		else	{	x=(x+1)>>1;	}
			if(y%2==0)	{	  y=y>>1;	}		else	{	y=(y+1)>>1;	}
			p[i].x = (x%2)?0:1;		p[i].y =  (y%2)?0:1; 
		}
		for(i=0;i<=iter-2;i++)
		{
			n=mat[p[i].x][p[i].y];
			mat[0][0]=a*n;	mat[0][1]=b*n;	mat[1][0]=c*n;	mat[1][1]=d*n;
		}
		x = (x1%2)?0:1; 		y = (y1%2)?0:1;
		p(mat[x][y]);	nl;
	}
}
