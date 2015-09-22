//      template by Utkarsh trivedi
//      problem id-        NFURY               Based on-
#include<stdio.h>
#define s(x) scanf("%d",&x)
#define p(x) printf("%d",x)
#define sl(x) scanf("%lld",&x)
#define pl(x) printf("%lld",x)
#define nl   printf("\n")
#define chk   printf("hello    ")
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
int Floor(int A[], int l, int r, int key)
{
    int m;
 
    while( r - l > 1 )
    {
        m = l + (r - l)/2;
 
        if( A[m] <= key )
            l = m;
        else
            r = m;
    }
 
    return A[l];
}
 
// Initial call
int Floor(int A[], int size, int key)
{
    return Floor(A, 0, size, key);
}
int main()
{
	int save[32],n,count,i,idx;
	for(i=1;i<32;i++)
	save[i]=i*i;
	int t;
	s(t);
	while(t--)
	{
		int count=0;
		s(n);
		while(1)
		{
			n=n-Floor(save,32,n);  count++;
			if(n==0)  break;
		}
		p(count);
		nl;
	}

}
