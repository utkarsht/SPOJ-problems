/*		greedy algo work here --
 1) Sort the activities according to their finishing time
2) Select the first activity from the sorted array and print it.
3) Do following for remaining activities in the sorted array.
…….a) If the start time of this activity is greater than the finish time of previously selected activity then select this activity and print it.
*/



#include<iostream>
#include<string.h>
#include<algorithm>
#define sz 100001		//00
using namespace std;
struct two
{
	int x;	int y;
};
bool operator<(two const&a, two const&b)
{
	return (b.y>a.y);
}
int main()
{
	int t,n,i;
	cin>>t;
	two a[sz];
	while(t--)
	{
		int count=1;
		cin>>n;
		for(i=0;i<n;i++)
			cin>>a[i].x>>a[i].y;
		sort(a,a+n);
//		for(i=0;i<n;i++)
//			cout<<a[i].x<<"  "<<a[i].y<<endl;
		int prev_end = a[0].y;
		for(i=1;i<n;i++)
		{
			if(a[i].x>=prev_end)
			{
				count++;
		     	prev_end = a[i].y;
			}	
		}
		cout<<count<<endl;
	}
}
