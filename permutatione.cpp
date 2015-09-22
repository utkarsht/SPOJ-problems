
#include<iostream>
#include<cmath>
#include<cstring>
	using namespace std;
int main()
{
	int a[10],d[10], i=0, j = 0, k = 0, l=0, m=0, c, temp, sum = 0, sum2 = 0, sum3 =0, p,n=0,r=0,t=0;
		char b[10];
	cout << "enter the word";
	cin >>b;
	n=strlen(b);
	while (n > 0)
	{
		sum = sum * 10 + n;
		n--;
		j++;
		sum3 = sum3 * 10 + j;
	}
	for (i = sum3; i <= sum; i++)
	{
		c = i;
		k = 0;
		r=0;
		while (c > 0)
		{
			a[k++] = c % 10;
			d[r++]=c%10;
			c /= 10;
		}
		//cout<<a[0]<<a[1]<<a[2]<<endl;
	//	cout<<d[0]<<d[1]<<d[2]<<endl;
		
		for (l = 0; l < j; l++)
		{
			for (m = 0; m < j-l; m++)
			{
				if (a[m] < a[m + 1])
				{
					temp = a[m];
					a[m] = a[m + 1];
					a[m + 1] = temp;
				}
			}
		}
		//cout<<'#'<<a[0]<<a[1]<<a[2]<<endl;
		//cout<<'&'<<d[0]<<d[1]<<d[2]<<endl;
		sum2 = 0;
		for (p = 0; p < j; p++)
			sum2 = sum2 * 10 + a[p];
			
		if (sum == sum2)
 {    for(t=0;t<j;t++)
    {   p=d[t]-1; 
        cout<<b[p];}
		cout<<endl ;   }
	}
}
