// key point is after condition of maxima ds/da = 0
//  we get a as 55 + 56 line then sustitute it in formula for S

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
#include<iomanip>
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
#define gc getchar_unlocked
void sfast(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}
*/
int main()
{
	int t,v;
	s(t);
	long double a,h,s;
	
	double k = 0.86602540378443864;
	while(t--)
	{
		s(v);
		a = (double)(3*v)/(k*k);
		
		a = pow(a,1.0/3);
		h = (double)(2*v)/(a*a*k);
		s = a*a*k + 3*a*h;
		
		cout<<std::setprecision(14)<<s<<endl;
	}

}
