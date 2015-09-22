//                  method ---- http://www.purplemath.com/modules/factzero.htm
#include<stdio.h>
#include<math.h>
#include<time.h>
#define s(x)  scanf("%ld",&x)
#define p(x)  printf("%ld\n",x)
int main()
{
	long t,n,count;
/*	clock_t begin, end;
    double time_spent;
    begin = clock();*/
	s(t);
	while(t--)
	{
		   count=0;
		s(n);
		while(n)
		{
			count+=n/5;
			n=n/5;
		}
		p(count);
	}
	/*end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	p(time_spent);*/
	return 0;
}



