#include<bits/stdc++.h>
using namespace std;
#define M 50
struct cylinder
{
	int ox;
	int nt;
	int wt;
};
int main()
{
	int t,ox,nt,total;
	cin>>t;
	cylinder cy[M];
	while(t--)
	{
		cin>>ox>>nt;
		cin>>total;
		for(int i=0;i<total;i++)
		{
			cin>>cy[i].ox>>cy[i].nt>>cy[i].wt;
		}
		for(int i=1;i<=total;i++)
		{
			// two variable knapsack condition here
		}
	}
}
