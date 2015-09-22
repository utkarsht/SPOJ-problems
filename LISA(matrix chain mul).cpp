//	https://github.com/geronimo/spoj/blob/master/LISA/lisa.cpp
//  the key point of program was to seperate operator and numbers then process

#include<bits/stdc++.h>
#define M 102
#define MAX 2147483647
#define MIN -MAX
using namespace std;
string str;
vector<int> number;
vector<char> opt;
int cal(int a,char b,int c)
{
	if(b=='+')			return a+c;
	else if(b=='*')		return a*c;
}
int main()
{
	int u,L,i,k,j,p1,p2;
	int s[M][M];
	int t[M][M];	
	cin>>u;
	while(u--)
	{
		cin>>str;
		number.clear();
		opt.clear();
		memset(&s,0,sizeof(s));
		for(i=0;i<M;i++)
		{
			for(j=0;j<M;j++)
			{
				t[i][j] = MAX;
			}
		}
		int n = str.length();
		for(i=0;i<n;i++)
		{
			if(i%2==0)
				number.push_back(str[i]-'0');
			else
				opt.push_back(str[i]);
		}
		n = number.size()+1;
		for(i=0;i<n;i++)
		{
			s[i][i] = t[i][i] = number[i];
		}
		for(L=2;L<n;L++)
		{
			for(i=0;i<n-L+1;i++)
			{
				j = i+L-1;
			//	s[i][j] = MAX;		t[i][j] = MIN;
				for(k=i;k<j;k++)
				{
				//	cout<<i<<"  "<<k<<"  "<<k+1<<"  "<<j<<endl;
					p1 = p2 = 0;
					if(opt[k]=='+' || opt[k]=='*')
					{
						p1 = cal(s[i][k] , opt[k] , s[k+1][j]);
						p2 = cal(t[i][k] , opt[k] , t[k+1][j]);
					}
					if(p1>s[i][j])
						s[i][j] = p1;  
					if(p2<t[i][j])
						t[i][j] = p2;
				}
			}
		}
		cout<<s[0][n-2]<<" "<<t[0][n-2]<<endl;
	}
}
