// choclate divison is based on greedy algo

#include<stdio.h>
#include<string.h>
#include<math.h>
#define s(x) scanf("%d",&x)
#define p(x) printf("%d",x)
#define sl(x) scanf("%lld",&x)
#define pl(x) printf("%lld",x)
#define gap	printf(" ")
#define nl   printf("\n")
#define chk   printf("hello    ")
#define F(x)	for(int i=0;i<x;i++)
#define all(c) (c).begin(),(c).end()
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
typedef long long ll;
typedef unsigned long long ull;


#include<iostream>
#include<set>
#include<map>
#include<list>
#include<vector>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;

//void print(int *a,int n)
//{	nl;	F(n)	{	p(a[i]);	space;	}	nl;		}

/*
#include<time.h>
#define timestart int tstart = clock()
#define printtime (double)(clock()-tstart)/CLOCKS_PER_SEC
*/
/*
#define gc getchar_unlocked
void sfast(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}
*/
struct vd
{
	int value;
	bool direction;
};
bool operator<(const vd &v1 , const vd &v2)
{
	if(v1.value == v2.value)
		return v1.direction < v2.direction;
	return v1.value < v2.value;
}
int main()
{
	int t,i,m,n;
	bool a;
	int ht,vt;
	s(t);
	while(t--)
	{
		s(m);	s(n);
		int sum = 0;
		ht = vt = 0;
		vd v[m+n-2];
		if(m>n)		a = 1;		else	a = 0;
		for(i=0;i<m-1;i++)
		{
			s(v[i].value);		v[i].direction = a;
		}	
		for(i=m-1;i<m+n-2;i++)
		{
			s(v[i].value);		v[i].direction = 1-a;
		}
		sort(v,v+m+n-2);
			
		for(i=m+n-3;i>=0;i--)
		{
			if(v[i].direction == a )	{	sum += v[i].value*(ht+1);	vt++;	}
			else						{	sum += v[i].value*(vt+1);	ht++;	}
		}
		p(sum);		nl;
	}

}
