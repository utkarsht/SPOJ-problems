#include<iostream>
using namespace std;
int main()
{
	int i,a[4],b[4];
	float r,max;
	while(1)
	{
		for(i=0;i<4;i++)
			cin>>a[i];
		for(i=0;i<4;i++)
			cin>>b[i];
		if(a[0]==-1 &&a[1]==-1 &&a[2]==-1 &&a[3]==-1 && b[0]==-1&& b[1]==-1&& b[2]==-1&& b[3]==-1)   break;
		if(a[0]==0 &&a[1]==0 &&a[2]==0 &&a[3]==0 )   cout<<"0 0 0 0\n";
		else
		{
		max=(float)a[0]/b[0];
		for(i=0;i<4;i++)
		{
			r=(float)a[i]/b[i];
			if(r>max)
			max=r;
		}
		if(max==0)  max=1;
		if(max>(int)max)  max=(int)max +1;
		for(i=0;i<4;i++)
		{
			cout<<b[i]*max-a[i]<<" ";
		}
		cout<<endl;
	}
    }
}
