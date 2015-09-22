// Stable marriage problem - the algo is as follows , Each time we keep on sending men to women if 
// he is free then try to put him with women if she is vacent then just put him with her ( not permanent)
// otherwise check preference of women for new comer and existing one if new comer is of
// more preference then replace it otherwise try another women for that men   Keep on this untill
// a single man is vacant.
#include<bits/stdc++.h>
using namespace std;
#define M 510		
int wprefer[M][M],mprefer[M][M],n,wpair[M],mpair[M];
bool freem[M];
bool chk_preferce_of_new_over_existing(int w,int m,int m1)
{
	for(int i=0;i<n;i++)
	{
		if(wprefer[w][i]==m)
			return 1;
		else if(wprefer[w][i]==m1)
			return 0;
	}
}
int main()
{
	int t,i,w,p,m,j,m1;
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	cin>>t;
	while(t--)
	{
		cin>>n;
		memset(&freem,1,sizeof(freem));
		memset(&wpair,-1,sizeof(wpair));
		for(i=0;i<n;i++)
		{
			cin>>w;		w--;
			for(j=0;j<n;j++)
			{
				cin>>p;		p--;
				wprefer[w][j] = p;
			}
		}
		for(i=0;i<n;i++)
		{
			cin>>m;		m--;
			for(j=0;j<n;j++)
			{
				cin>>p;		p--;
				mprefer[m][j] = p;
			}
		}
		int freemen = n;
		while(freemen>0)
		{
			for(m=0;m<n;m++)
				if(freem[m]==true)
					break;
			for(int j=0;j<n && freem[m]==true;j++)
			{
				w = mprefer[m][j];
				if(wpair[w]==-1)
				{
					wpair[w] = m;
					mpair[m] = w;
					freem[m] = false;
					freemen--;
				}
				else
				{
					m1 = wpair[w];
					if(chk_preferce_of_new_over_existing(w,m,m1)>0)
					{
						wpair[w] = m;
						mpair[m] = w;
						freem[m] = false;
						freem[m1] = true;
					}
				}
			}
		}
		for(i=0;i<n;i++)
		{
			cout<<i+1<<" "<<mpair[i]+1<<endl;
		}
	}
}
