#include<string.h>
#include<stdio.h>
#define s(x) scanf("%d",&x)
#define p(x) printf("%d",x)
#define nl   printf("\n")
#define dl(x)  ( x & (-x) )
#define sz 125

int a[sz][sz];
int ft[sz][sz];
int n;
int read(int i,int j)
{
	int sum=0,save=j;
	while(i>0)
	{
		j=save;
		while(j>0)
		{
			sum+=ft[i][j];
			j-=dl(j);
		}
		i-=dl(i);
	}
	return sum;
}
void show()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			p(a[i][j]);	printf("  ");
		}
		nl;
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			p(ft[i][j]);	printf("  ");
		}
		nl;
	}
}
int read2(int x1,int y1,int x2,int y2)
{
	int a,b,c,d;
	a = read(x2,y2);	b = read(x2,y1-1);	   c = read(x1-1,y2);	 d = read(x1-1,y1-1);
	return	(d+a-b-c);
}
void update(int x,int y,int d)
{
	int i,j;
	for(i=x ; i<=n ; i+= dl(i))
	{
		for(j=y ; j<=n ; j+= dl(j))
		{
			ft[i][j] += d;
		}
	}
}

int main()
{
	int t,x1,y1,x2,y2,u,i,j,dif,sum;
	char str[10];
	s(t);
	while(t--)
	{
		s(n);
		memset(&a,0,sizeof(a));
		memset(&ft,0,sizeof(ft));
		while(1)
		{
			scanf("%s",str);
			if(strcmp(str,"END")==0)		break;
			if(strcmp(str,"SUM")==0)
			{
				s(x1);	s(y1);	s(x2);	s(y2);
				x1++;	y1++;	x2++;	y2++;
				sum = read2(x1,y1,x2,y2);
				p(sum);
				nl;
			}
			else
			{
				s(x1);	s(y1);	s(u);
				x1++;	y1++;
				dif = u - a[x1][y1] ;
				a[x1][y1] = u ;
				update(x1,y1,dif);
			}
		}
	//	show();
	}
}
