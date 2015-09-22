#include<iostream>
#include<list>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
int bsearch(int *a,int beg,int end,int item)
{
int mid=(beg+end)/2;                       // Find Mid Location of Array
while(beg<=end && a[mid]!=item)      // Compare Item and Value of Mid
{
if(a[mid]<item)
beg=mid+1;
else
end=mid-1;
mid=(beg+end)/2;
}
if(a[mid]==item)   return mid+1;
else   return -1;
}
int main()
{
	int t,i,n,a[102];
	vector<int> v;
	for(i=2;i<=101;i++)
	a[i]=i*i*i;
	list<int> l;
	for(i=1;i<1000100;i++)
	l.push_back(i);
	list<int>:: iterator p,p1;
	p=l.begin();    int k=2;
	while(true)
	{
	p=l.begin();
	while(p!=l.end())
	{
		if(*p%a[k]==0)
		{
			p1=p;
		 	p++;
		 	l.erase(p1);
		}
		else p++;
	}
	k++;
	if(k>100)  break;
    }
    p=l.begin();
    int size=0;
	while(p!=l.end())
	{
		v.push_back(*p);
		size++;	
		p++;
	}
	cin>>t;
	for(int j=1;j<=t;j++)
	{
		int count=0;
		cin>>n;
		int pos=bsearch(&v[0],0,size-1,n);
		if(pos==-1)
		cout<<"Case "<<j<<": Not Cube Free\n";
		else
		cout<<"Case "<<j<<": "<<pos<<endl;
	}
}
