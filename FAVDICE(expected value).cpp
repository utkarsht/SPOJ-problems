//   for understanding expected value - http://en.wikipedia.org/wiki/Coupon_collector%27s_problem
//   key point is -- any number must come once so as we are throwing the dice continuously probabilty of coming a particular number will reduce
//	 each time (  because the number which came before may come again and reduce the chance )
//   for this problem let n=12 , when we will throw the dice first time any number may come so first prob=1
//   then next time probability will reduce to 11/12 then 10/12 and so on
//   and expected value =	(1/p1 + 1/p2 + 1/p3 --  ) * N so,   solution is

#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int cases;
    cin>>cases;
    while(cases--)
    {
        float n,t;
        cin>>n;
        t=n;
        float num=1;
        while(n-- > 1)
        {
            num+=float((t*1/n));
        }
        printf("%.2f\n",num);
    }
    return 0;
}
