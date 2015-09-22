#include <iostream>
#include <string.h>
using namespace std;
struct visit
{
	bool ck;
	bool ans;	
};
int mod(char *b,int a)
{
	int num2 = 0;
	for(int i=0;b[i];i++)
	{
		num2=(num2*10+(int)b[i]-'0')%a;
	}
	return num2;
}
int main()
{
	char str[250];
	int count = 0,n,p;
//	strcpy(str,"24");
//	cout<<mod(str,2)<<" "<<mod(str,3)<<" "<<mod(str,5)<<endl;
	visit v[10];
    while(scanf("%s",str)!=EOF)
    {
	//	memset(&v,0,sizeof(visit));
		for(int i=0;i<10;i++)	v[i].ck = 0;
     	v[0].ck = 1;	v[0].ans = 0;
     	v[1].ck = 1;	v[1].ans = 1;
     	count = 0;
     	int l =strlen(str);
     	for(int i=0;i<l;i++)
     	{
     		p = str[i]-'0';
    		if(!v[p].ck)
     		{
     			v[p].ck = 1;
     			n = mod(str,p);
     			if(n==0)
     				v[p].ans = 1,
     				count++;
     			else
     				v[p].ans = 0;
     		}
     		else
     			count += v[p].ans;
     	}
     	cout<<count<<endl;
     }
}
