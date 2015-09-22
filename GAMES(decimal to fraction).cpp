#include<bits/stdc++.h>
using namespace std;
int gcd(int m, int n)     	
{
   int  r;                
   while (n != 0) 
   {      
      r = m % n;          
      m = n;            
      n = r;
   }                      
   return m;              
}
int digitin(int n)
{
	int dig=0;	while(n>0)	{  n/=10;	dig++;	}
	return dig;
}
int main()
{
	double n;
	int t,a,b,ten;
	cin>>t;
  	while(t--)
  	{
  		b = 0;
  		scanf("%d.%d",&a,&b);
  		ten = pow(10,digitin(b));
  		ten /= gcd(b,ten);
  		cout<<ten<<endl;
  	}	
}
