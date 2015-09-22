#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,cur_len,i,prev_index,max_len,end;
	string str;
	int pos[257];
	cin>>t;
	while(t--)
	{
		cin>>str;
		cur_len = max_len = 1;
		int l = str.length();
		memset(&pos,-1,sizeof(pos));
		pos[str[0]] = 0;
		for(i=1;i<l;i++)
		{
			prev_index = pos[str[i]];
			if(prev_index == -1 || (i-prev_index)>cur_len)		// Eihter not visited or visited before current substring
				cur_len++;
			else
			{
				if(cur_len>max_len)
				{
					max_len = cur_len;
					end = i;
				}
				cur_len = i-pos[str[i]];
			}
			pos[str[i]] = i;
		}
		if(cur_len>max_len)
		{
			max_len = cur_len;
			end = i;
		}
		//cout<<max_len<<endl<<end<<endl;
		for(i = end-max_len; i<end;i++)
			cout<<str[i];
		cout<<endl;
	}
}
