#include<iostream>
#include<fstream>
using namespace std;
#define sz 100
int main()
{
	int i,j,k,l;
	fstream fout;
//	fout.open("E://data1.txt");
	for(i=2;i<=sz;i++)
	{
		for(j=2;j<=sz;j++)
		{
			for(k=j;k<=sz;k++)
			{
				for(l=k;l<=sz;l++)
				{
					if(i*i*i==j*j*j+k*k*k+l*l*l)
					 cout<<"Cube = "<<i<<", Triple = ("<<j<<","<<k<<","<<l<<")\n";
				}
			}
		}
	}
}
