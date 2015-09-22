// Every pattern that is present in a text must be a 'prefix' of one of the all 'suffix' of text.
// this is main point of suffix array and trie
// Reference -- http://www.geeksforgeeks.org/suffix-array-set-1-introduction/

// algorithmist -  disubstr

#include<iostream>
#include<string.h>
#include<algorithm>
#define M 1005
using namespace std;
struct suffix
{
	int index;
	char* suff;
};

char text[M];
suffix s[M];
int lcp[M];
	
int cmp(suffix a,suffix b)
{
	return strcmp(a.suff,b.suff) < 0 ? 1 : 0 ;
}

long long buildlcp(char* text,int *lcp)
{
	int l = strlen(text);
	for(int i=0 ; i<l ; i++)
	{
		s[i].index = i;
		s[i].suff  = text+i;
	}
	
	sort(s, s+l , cmp);	
	for(int i=0 ; i<l-1 ; i++)
	{
		int p = max(strlen(s[i].suff),strlen(s[i+1].suff));
		for(int j=0;j<p;j++)
		{
			if(s[i].suff[j]==s[i+1].suff[j])
				lcp[i]++;	
			else
				break;
		}
	}
	long long count = 0;
	for(int i=0 ; i<l-1 ; i++)
	{
		count += lcp[i];
	}
	count = (l*(l+1))/2 - count ; 
	return count;
}


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>text;
	    int l=strlen(text);
		memset(&lcp,0,sizeof(lcp));
		memset(&s,0,sizeof(s));
		cout<<buildlcp(text,lcp)<<endl;
	}
}
