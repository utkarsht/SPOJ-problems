/*		because phi(i) = i-1 for prime which is greatest so phi(i)/i will be max for primes so this
		question based on primality testing we need to get greatest prime less than or equal to n
		if n is even reduce 1 if it is prime ok otherwise keep on decreasing 2 and check for primality
		for making it fast use some precalculated prime and if n%a[i]==0 then direct return 0 otherwise go for miller rabin test

		for miller rabin these 3 condition remember - temp!=p-1 && b!=1 && b!=p-1   then if b=1 composite	b=p-1 probable prime
*/
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int a[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
int pre;
ll mulmod(ll a, ll b, ll mod)
{
    ll x = 0,y = a % mod;
    while (b > 0)
    {
        if (b % 2 == 1)
        {    
            x = (x + y) % mod;
        }
        y = (y * 2) % mod;
        b /= 2;
    }
    return x % mod;
}
ll pow(ll a, ll b, ll c)
{
	ll x = 1, y = a%c;
	while(b>0)
	{
		if(b&1) x = mulmod(x,y,c);				// here also mulmod is called
		y = mulmod(y,y,c);
		b = b>>1;
	}
	return x;
}
bool miller(ll p,int iteration)
{
	for(int i=0;i<pre;i++)
	{
		if(p==a[i])
			return 1;
		else if(p%a[i]==0)
			return 0;
	}
	ll s = p-1;		ll temp,b;		ll a;
	while(s%2==0)	s /= 2;
	for(int i=0;i<iteration;i++)
	{
		a = rand()%(p-1) + 1;	temp = s;
		b = pow(a,s,p);
		while(temp!=p-1 && b!=1 && b!=p-1)
		{
			b = mulmod(b,b,p);
			temp = temp<<1;
		}
		if(temp%2==0 && b!=p-1)
			return false;
	}
	return true;
}
int main()
{
	cin.sync_with_stdio(0);		cout.sync_with_stdio(0);
	int t;		int iteration = 2;
	pre = sizeof(a)/sizeof(int);
	cin>>t;		ll n;
	while(t--)
	{
		cin>>n;
		if(n<=3)
		{	cout<<n<<endl;	continue;	}
		if(n%2==0)		n--;
		while(1)
		{
			if(miller(n,iteration))
			{
				cout<<n<<endl;	break;
			}
			else
				n-=2;
		}
	}
}
