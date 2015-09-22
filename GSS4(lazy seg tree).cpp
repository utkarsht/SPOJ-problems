//	In this que main point is - after some time (at most 7) every node will become 1 so we don't need to update them
//	i.e. if at a subtree add is equal to number of element don't go for updation (line:44  <- main optimistaion)

#include <stdio.h>
#include <math.h>
typedef long long ll;
ll st[900108];
ll a[100001];
void swap(int& a,int& b)
{
	int t;
	t = a;	a = b;	b = t;
} 
void build(int lo,int hi,int idx)
{
    if(lo == hi)
    {
        st[idx] = a[lo];
        return;
    }
    int mid = (lo+hi) >> 1;
    build(lo,mid,2*idx);
    build(mid+1,hi,2*idx+1);
    st[idx] = st[2*idx] + st[2*idx+1];
}
 
ll query(int lo,int hi,int i,int j,int idx)
{
	 if(i>hi or j<lo)
        return 0;
     if(i<=lo && j>=hi)
        return (ll)st[idx];
    else
    {
        int mid = (lo+hi) >> 1;
        return (ll) query(lo,mid,i,j,2*idx) + query(mid+1,hi,i,j,2*idx+1);
    }
}
 
void update(int lo,int hi,int i,int j,int idx)
{
    if(i>hi or j<lo)    
		return;
    if(hi-lo+1 == st[idx])
        return;
    if(hi == lo)
    {
   	    st[idx] = floor(sqrt(st[idx]));
        return;
    }
    int mid = (lo+hi) >> 1;
    update(lo,mid,i,j,2*idx);
    update(mid+1,hi,i,j,2*idx+1);
	st[idx] = st[2*idx] + st[2*idx+1];
}
 
int main()
{
    int ch,x,y,q,n;
    int j = 1;
    while(scanf("%d",&n) != EOF)
    {
        for (int i = 0; i < n; ++i)
        {
        	scanf("%d",&a[i]);
        }
        build(0,n-1,1);
        scanf("%d",&q);
        printf("Case #%d:\n",j);
        while(q--)
        {
            scanf("%d %d %d",&ch,&x,&y);
			if(x>y)		swap(x,y);
            if(ch == 0)
                update(0,n-1,x-1,y-1,1);
            else
            	printf("%d\n",query(0,n-1,x-1,y-1,1));
        }
        printf("\n");
        j++;
    }
} 
