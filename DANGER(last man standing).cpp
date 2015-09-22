#include<iostream>
#include<math.h>
#include<list>
using namespace std;
long term(long k)
{
	return 2*k-1;
}
int main()
{
	long n,i;
	string str;
	while(1)
	{
	  cin>>str;
	  if(str=="00e0")   break;
	  n= ( (str[0]-48)*10 +	(str[1] - 48) ) * (pow(10,str[3]-48)) ;
	  //  method 1:  by seeing the repetitions    generated a   formula
	  int p=(int)(log10(n)/log10(2));
	 //cout<<p<<"        "<<n-pow(2.0,p)+1<<endl;
	  cout<<term(n-pow(2.0,p)+1)<<endl;
	 /*    method 2:  by list  in which we iterate over complete list so can be use for any passes  but above can be use for 2
	  list<long> l;
       for(i=0;i<n;i++)
       l.push_back(i+1);
       list<long> :: iterator p,p1,p2,p3;
       p=l.begin();
       p++;
       while(n!=1)
       {
       	p1=p++; 
       	p2=l.end();  p2--;
       	p3=l.end();  p3--;   p3--;
       	if(p1==p2 || p1==p3)
       	p++;
       	l.erase(p1);
       	p++;
       	n--;
       }
       cout<<*(l.begin())<<endl;  */
	}
	
}
