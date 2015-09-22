#include<stdio.h>

int main()

{

double n;

int i;

scanf("%lf",&n);

long a[(int)n];

for(i=0;i<(int)n;i++)

scanf("%ld",&a[i]);

printf("\n");

for(i=0;i<(int)n;i++)

{

    long count=0;

    while(a[i]!=0)

{

count=count + (int)(a[i]/5);

a[i]/=5;

}

printf("%ld\n",count);

}

return 0;

}

