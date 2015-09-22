//in an equilateral triangle if a point is ther whose distance from vetices are
//a b c then its are is 1/2(a*a*sqrt(3)/4 + b_ + c_ + 3*sqrt(s(s-a)(s-b)(s-c)) )
//here s=(a+b+c)/2
#include<iostream>
#include<math.h>
#include<stdio.h>
#include<string.h>
#define s(x) scanf("%d",&x)
#define p(x) printf("%d",x)
#define sl(x) scanf("%lld",&x)
#define pl(x) printf("%lld",x)
#define gap	printf(" ")
using namespace std;
int main()
{
	int t,i,a[3];
	s(t);
	double sum,k=0.21650635094610966;
	double s;
	while(t--)
	{
		s(a[0]);	s(a[1]);	s(a[2]);
		sum = 0.0;
		for(i=0;i<3;i++)
			sum+=(double)k*a[i]*a[i];
			
		s = (a[0]+a[1]+a[2])/2.0;
		sum+=1.5* sqrt(s*(s-a[0])*(s-a[1])*(s-a[2]));
		printf("%.2f\n",sum);
	}
}
