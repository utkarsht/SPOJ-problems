// Suppose number with shaktiman is even so he can make it odd(1 is factor) or even(2 is factor) but for winning he 
// will always make it odd because with odd you can come only to even position (odd has all odd factors and odd-odd=even)
// then again shaktiman will make him odd and so on finally odd will be 1 and kilvish will lose.
// if in starting he has odd then kilvish will become even and in same way kilvish will won.  SO CODE-

#include<iostream>
using namespace std;
int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		if(n%2==1)
			cout<<"Sorry Shaktiman\n";
		else
			cout<<"Thankyou Shaktiman\n";
	}
}
