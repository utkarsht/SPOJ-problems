/*Lets say that lxh is ‘-‘(negative) and hhb is ‘+'(positive).According to the problem, if the chosen coins belong to 
  the same person, the new coin will belong to hhb else lxh. Going with our assumption, if the two signs are same 
  it will result in ‘+'(hhb) else ‘-‘(lxh), which is obviously true. 
  So irrespective of the order of coins chosen, if the number of ‘-‘ coins is even it will result in ‘+’ else ‘-‘.

  So we can see if the number of coins initially belonging to lxh is even, it will finally belong to hhb else lxh.
*/

#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int t,n,l,h;
	char str[5];
	cin>>t;
	while(t--)
	{
		cin>>n;
		l = h = 0;
		for(int i=0;i<n;i++)
		{
			cin>>str;
			if(strcmp(str,"lxh")==0)
				l++;
			else
				h++;
		}
		if(l%2==0)
			cout<<"hhb\n";
		else
			cout<<"lxh\n";
	}
}
