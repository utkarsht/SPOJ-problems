#include<iostream>
#include<math.h>
using namespace std;
struct val
{
	int a,b,c;
};
val operator+(val a,val b)
{
	val temp;
	temp.a = a.a + b.a;
	temp.b = a.b + b.b;
	temp.c = a.c + b.c;
	return temp;
}
val req;
int max(int a,int b)
{
	if(a>=b)  return a;
	else return b;
}
void show(val *a,int n)
{
	for(int i=1;i<pow(2.0,n);i++)
	{
		val sum;
		sum.a = sum.b = sum.c = 0;
		for(int j=0;j<n;j++)
		{
			if(i&(1<<j))
			{
		//		cout<<a[j].a<<"  "<<a[j].b<<"  "<<a[j].c<<endl;
				sum = sum + a[j];
			//	cout<<j<<endl;
			}
	    }
	//    cout<<sum.a<<" "<<sum.b<<" "<<sum.c<<endl<<endl;
	    if(req.a==sum.a  &&  req.b==sum.b  &&  req.c==sum.c) { cout<<"yes\n";  return; }
	}
    cout<<"no\n";
}
int main()
{
	int t,n,x,y,z;
	cin.sync_with_stdio(0);
	cout.sync_with_stdio(0);
	cin>>t;
	for(int j=1;j<=t;j++)
	{
		cin>>x>>y>>z;
		req.a = x;		req.b = y;		req.c = z;
		cin>>n;
		val a[n];
		for(int i=0;i<n;i++)
		{
			cin>>x>>y>>z;
			a[i].a = x;		a[i].b = y;		a[i].c = z;
		}
		cout<<"Case #"<<j<<": ";
		show(a,n);
	}
}
