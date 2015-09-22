// Words 1 -   problem based on euler path in directed graph so 2 conditions must be satisfied 
//			1. Indegree and Outdegree must be equal for each vertex	( except for first and last char )
//			2. Graph should be strongly connected

#include<iostream>
#include<string.h>
#include<vector>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
bool visit[30];
bool mark[30];

void dfs(vvi& g,int v)
{
	visit[v] = 1;
	for(int i=0;i<g[v].size();i++)
	{
		if(visit[g[v][i]]==0)
			dfs(g,g[v][i]);
	}
}

bool isconnected(vvi& g,int source)
{
	dfs(g,source);
	for(int i=0;i<26;i++)
	{
		if(mark[i] && !visit[i])
			return false;
	}
	return true;
}

int main()
{
	int t,n,i;
	int a[26][2]={0} , source;
	string str;
	vvi g(30);
	cin>>t;
	while(t--)
	{
		cin>>n;
		memset(&a,0,sizeof(a));
		memset(&visit,0,sizeof(visit));
		memset(&mark,0,sizeof(mark));
		for(i=0;i<n;i++)
		{	
			cin>>str;
			a[str[0]-'a'][1]++;
			a[str[str.length()-1]-'a'][0]++;
			g[str[0]-'a'].push_back(str[str.length()-1]-'a');
			mark[str[0]-'a'] = 1;
			mark[str[str.length()-1]-'a'] = 1;
		}
		if(n==1)	{	cout<<"Ordering is possible.\n";	continue;	}
		
		int start=0,end=0;
		source = str[0]-'a';
		for(i=0;i<26;i++)
		{
			if(a[i][0]==a[i][1]+1)
				end++;
			else if(a[i][1]==a[i][0]+1)
				{	start++;	source = i;		}
			else if(a[i][0]!=a[i][1])
				break;
		}
		
		if(i==26 && ((start==1 &&  end==1)  || (start==0 &&  end==0)) && isconnected(g,source))
			cout<<"Ordering is possible.\n";
		else 
			cout<<"The door cannot be opened.\n";
	}
}
