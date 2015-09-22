//      template by Utkarsh trivedi
//      problem id-                       Based on-
#include<stdio.h>
#include<math.h>
#define s(x) scanf("%d",&x)
#define p(x) printf("%d",x)
#define sl(x) scanf("%lld",&x)
#define pl(x) printf("%lld",x)
#define nl   printf("\n")
#define chk   printf("hello    ")
typedef long long ll;
#include<iostream>
#include<list>
using namespace std;

// for fast input include below one
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
#define base 2
ll abs(ll x)
{
	return (x>0)?x:-x;
}
int main()
{
	ll num;
//	int t;
	//for(t=-17;t<17;t++)
	{
	sl(num);
	//num=t;
	list<bool> l;
	while(1)
	{
		l.push_front(abs(num)%(base));
		if(num<0)  num=ceil((double)(-num)/(base));
		else if(num>0)  {  num=num/base;   num = -num;  }
		if(num==0) break;
	}
	list<bool> :: iterator q= l.begin();
	//cout<<t<<"    :  ";
	while(q!=l.end())
	{
		p(*q);
		q++;
	}
//	nl;
	}
}
