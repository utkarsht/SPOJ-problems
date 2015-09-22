#include<bits/stdc++.h>
#define M 1002
using namespace std;
int main()
{
	char str[M];
	int lowereven,lowerodd,uppereven,upperodd;
	int fC,fL;
	while(cin>>str)
	{
		lowereven = lowerodd = uppereven = upperodd = 0;
		int l = strlen(str);
		for(int i=0;i<l;i+=2)
		{
			if(islower(str[i]))
				lowereven++;
			else
				uppereven++;
		}
		for(int i=1;i<l;i+=2)
		{
			if(islower(str[i]))
				lowerodd++;
			else
				upperodd++;
		}
		fC = lowereven + upperodd  ;
		fL = lowerodd  + uppereven ; 
		cout<<((fC>fL)?fL:fC)<<endl;
	}
}
