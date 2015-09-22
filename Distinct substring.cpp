//      template by Utkarsh trivedi
//      problem id-    Disubstr                   Based on-	count of trie nodes	(WHICH I USED HERE)	or   suffix array & lcp calculation
//		Total nodes in a trie = number of substring
#include<stdio.h>
#include<string.h>
#define s(x) scanf("%d",&x)
#define p(x) printf("%d",x)
#define nl	 printf("\n")
typedef long long ll;



struct node
{
	char data;
	node* child[128];
};

int print(node *t)
{
	if(t)
	{
		p((int)t->data-'0');	printf("  ");
		for(int i=0;i<128;i++)
		{
			if(t->child[i]!=NULL)
			{	print(t->child[i]);		}
		}
	}	
}

int main()
{
	int t,i,j,k,l,m,n;
	node *temp;
	char str[1002];
	s(t);
	while(t--)
	{
		int count=0;
		node* root=new node;
		root->data=char(1);
		temp=root;
		memset(&temp->child,0,sizeof(temp->child));
		scanf("%s",str);	l=strlen(str);
		for(i=0;i<l;i++)
		{
			temp=root;
			for(j=i;j<l;j++)
			{
				k=(int)str[j];
				if(temp->child[k]==0)
				{
					for(m=j;m<l;m++)
					{
						k=(int)str[m];
						temp->child[k]=new node;
						count++;
						temp->child[k]->data=str[m];
						temp=temp->child[k];
						memset(&temp->child,0,sizeof(temp->child));
					}
					break;
				}
				else
				{
					temp=temp->child[k];
				}
			}
		}
		print(root);
		p(count);
		nl;
	}

}
