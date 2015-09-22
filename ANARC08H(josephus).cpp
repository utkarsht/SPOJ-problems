//       For josephus problem  http://manyprogrammingtutorials.blogspot.in/2014/03/josephus-problem.html
//       the key point of problem is to write solution for various n for various k then write a recurrence relation then change that to iteration
//       recurrence relation which you will get is   --  josephus( n, k )  =  (josephus(n - 1, k) + k-1) % n + 1
#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int d,i,n;
	while(1)
	{
	   cin>>n>>d;
	   if(n==0  && d==0)   break;
	   int ans=0;
       for(i=1;i<=n;i++)
       {
       		ans=(ans+d)%i;
       }
       cout<<n<<" "<<d<<" "<<1+ans<<endl;
	}
	
}
