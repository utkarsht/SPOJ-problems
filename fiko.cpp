#include<fstream>
#include<iostream>
#include<cmath>
using namespace std;
bool prime(int n)
{
	int i;
	for(i=2;i<sqrt(n)+1;i++)
	if(n%i==0)  return 0;
	return 1;
}
int main()
{
	int d;
	ifstream fin;
   	fin.open("E:\data1.txt",ios::in);
   	fin>>d;
   	cout<<d;
   	fin>>d;
   	cout<<d;
}
