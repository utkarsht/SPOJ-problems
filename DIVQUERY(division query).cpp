//		help - editorial 
//	method - first construct all factor of each number   and saved in factor array then for each array element
//	save that index in respective  fact_idx array and then binary search for left and right idx (totally bookeeping)
#include<bits/stdc++.h>
#define M 100002
using namespace std;
int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	int a[M];	int l,r,k,num;
	vector<int>  factor[M];			//array of vectors useful over vector of vector when 1 size you know
	vector<int>  fact_idx[M];
	for(int i=1;i<M;i++)			// Way to store factor of each number in a range
	{
		for(int j=i;j<M;j+=i)
			factor[j].push_back(i);
	}
	
	/*for(int i=1;i<50;i++)
	{
		cout<<i<<" : ";
		for(int j=0;j<factor[i].size();j++)
		{
			cout<<factor[i][j]<<"  ";
		}
		cout<<endl;
	}*/
	int n,q;
	cin>>n>>q;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		for(int j=0;j<factor[a[i]].size();j++)		// index will be in sorted order automatically
		{
			fact_idx[factor[a[i]][j]].push_back(i);			// for each factor saving index of array number
		}
	}
	while(q--)
	{
		cin>>l>>r>>k;	l--;	r--;
		/*for(int i=0;i<fact_idx[k].size();i++)
			cout<<fact_idx[k][i]<<"  ";
		cout<<endl;*/
		num = upper_bound(fact_idx[k].begin(),fact_idx[k].end(),r)-lower_bound(fact_idx[k].begin(),fact_idx[k].end(),l);
		cout<<num<<endl;
	}
}
