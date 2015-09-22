#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
	int a,d,i,min,min1,min2;
	while(1)
	{
		cin>>a>>d;
		if(a==0  && d==0)   break;
		int atack[a];
		int defend[d];
		cin>>atack[0];
		min=atack[0];
		for(i=1;i<a;i++)
		{   cin>>atack[i];
		    if(min>=atack[i])
		    min=atack[i]; 
	    }
	    cin>>defend[0];
	    min1=min2=defend[0];
		for(i=1;i<d;i++)
	    {	
		cin>>defend[i];
		}
		sort(defend,defend+d);
		min2=defend[1];
		//cout<<min<<endl<<min2<<endl;
		if(min>=min2)  cout<<"N\n";
		else cout<<"Y\n";
    }
}
