		//	http://www.geeksforgeeks.org/dynamic-programming-set-3-longest-increasing-subsequence/

#include<iostream>
#include<algorithm>
#include<functional>
#include<utility>
#include<string.h>
using namespace std;
struct cube
{
    int h;
    int l;
    int b;
};
bool operator<(const cube&a , const cube&b)
{
    return ( a.l*a.b > b.l*b.b ) ;
}
void swap(cube &a,cube &b)
{
    swap(a.h,b.h);
    swap(a.l,b.l);
    swap(a.b,b.b);
}
int main()
{
    cube c[200];
    int ht[200];
    int n,i,j,k,x,y,z;
    while(true)
    {
        int k=0;
        cin>>n;       if(!n)  break;
        int ans =-1;
        for(i=0;i<n;i++)
        {
            cin>>x>>y>>z;													// TRy all 6 permmutation
            c[k].l = x;     c[k].b = y;     c[k].h = z;         k++;
            c[k].l = z;     c[k].b = x;     c[k].h = y;         k++;
            c[k].l = y;     c[k].b = z;     c[k].h = x;         k++;
            c[k].l = x;     c[k].b = z;     c[k].h = y;         k++;
            c[k].l = z;     c[k].b = y;     c[k].h = x;         k++;
            c[k].l = y;     c[k].b = x;     c[k].h = z;         k++;
        }
        sort(c,c+k);
        memset(&ht,0,sizeof(ht));
        for(i=0;i<k;i++)
            ht[i] = c[i].h;
        for(i=1;i<k;i++)
        {
            for(j=0;j<i;j++)
            {
                if(c[i].b < c[j].b && c[i].l < c[j].l && ht[i] <= ht[j]+c[i].h)		//  LIS  see this checking carefully if ht is increasing by adding ith box then we add this
                    ht[i] = ht[j] + c[i].h;
            }
        }
        for(i=0;i<k;i++)
           ans = max(ans,ht[i]);
        cout<<ans<<endl;
    }
}


