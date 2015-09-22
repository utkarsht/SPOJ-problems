
// question based on pair and sorting
#include<iostream>
#include<map>
#include<string.h>
#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int t,k,i,n,g;
	cin>>t;
	while(t--)
	{
		cin>>n;
		char str[n][6];
		string str1[i];
		char save[40];
		map<string,pair<int,int> > m;
		map<string,pair<int,int> >:: iterator p;
	   	for(i=0;i<n;i++)
	   	{
	   		scanf("%s %s %s %s %s %s",str[i][0],str[i][1],str[i][2],str[i][3],str[i][4],str[i][5]);
		    str1[i]=str[i][0]+str[i][5];
	    }   
		sort(str1,str1+n);
		printf("%s %s %s %s %s %s ",str[i][0],str[i][1],str[i][2],str[i][3],str[i][4],str[i][5]);
		for(i=1;i<n;i++)
		{
			if(strcmp(str[i][0],str[i-1][0])==0   &&  strcmp(str[i][5],str[i-1][5])==0)
				count++;
			else
			{
				printf("%d\n",count);  count=1;
				printf("%s %s %s %s %s %s ",str[i][0],str[i][1],str[i][2],str[i][3],str[i][4],str[i][5]);
			}
		}
	}

}
