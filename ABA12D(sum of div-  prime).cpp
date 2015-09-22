// I first generate the sequence then find out the series that only 38 numbers are there in this range which i saved in array ans then 
// all query can be give easily for finding sequence - function used - sum of div , prime numbers , binary search

#include<bits/stdc++.h>
using namespace std;
int sumofdiv(int n)
{
	int t=sqrt(n);
	int sum = 0 ;
	if(n==1)	return 1;
	for(int i=2;i<=t;i++)
	{	
		if(n%i==0)
		{
			if(i==n/i)   sum+=i;
			else sum+=i+n/i;
		}
	}
	sum++;	sum+=n;
	return sum;
}
bool sch(int *prime,int key)
{
	for(int i=0;i<25;i++)
		if(key==prime[i])
			return 1;
	return 0;
}

int main()
{
	int t,a,b;
	cin>>t;
	vector<int> :: iterator k1,k2;
	int ans[] = {2,4,9,16,25,64,289,729,1681,2401,3481,4096,5041,7921,10201,15625,17161,27889,28561,29929,65536,83521,85849,146689,262144,279841,458329,491401,531441,552049,579121,597529,683929,703921,707281,734449,829921,1190281};
	vector<int> v(ans,ans+38);
	while(t--)
	{
		cin>>a>>b;
		k1 = lower_bound(v.begin(),v.end(),a);
		k2 = upper_bound(v.begin(),v.end(),b);
		cout<<k2-k1<<endl;
	}
}
