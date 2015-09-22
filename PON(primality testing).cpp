/*		primality testing miller rabin test , 
		source-http://community.topcoder.com/tc?module=Static&d1=tutorials&d2=primalityTesting
		Example for n = 561  https://www.youtube.com/watch?v=qfgYfyyBRcY
		
		in this method - i) we represent p-1 as 2^d * s ,   then 	ii) choose (random)a btw 0 to n-1 then get b = (a^s) % n
		if b % n == 1 or n-1 (actually -1 but mod>0)  then break		else  b = b*b 
		now finally if b%n = 1 return not prime   else  it is probable prime ( chk for another a and confirm if each time mod is n-1)
*/
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
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
bool miller(ll p, int iteration)
{
	if(p<2)					return false;  
    if(p!=2 && p%2==0) 		return false;
       
    ll s=p-1;	ll a,b,temp;
    while(s%2==0)	 s/=2;
    for(int i=0;i<iteration;i++)
    {
    	a = rand()%(p-1) + 1;	temp = s;			// here temp will be odd
    	b = pow(a,temp,p);
    	while(temp!=p-1 && b!=1 && b!=p-1)
    	{
    		b = mulmod(b,b,p);
    		temp = temp<<1;							// if loop goes once temp become even it is used to avoid infinite loop
    	}
    	if(b!=p-1 && temp%2==0)						// if temp even and  b!=p-1  then it is surely composite otherwise chk for dif a			
    		return false;
    }
    return true;
}
int main()
{
	cin.sync_with_stdio(0);
	cout.sync_with_stdio(0);
	int t;	bool flag;
	int iteration = 2;
	ll n,i;
	scanf("%d", &t);
	for(int j=1;j<=t;j++)
	{
		scanf("%llu", &n);
		if(miller(n,iteration))
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
}

