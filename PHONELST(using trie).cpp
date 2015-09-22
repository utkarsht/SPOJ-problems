#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#define s(x) scanf("%d",&x)
#define p(x) printf("%d",x)
#define space printf("   ")
#define nl	 printf("\n")
typedef long long ll;

using namespace std;

struct node
{
	char data;
	int size;
	node* child[10];
	node()	{	size=0;	}
};

void print(node *t)
{
	if(t)
	{
		p((int)t->data-'0');	printf(" ( %d ) ",t->size);		space;
		for(int i=0;i<10;i++)
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
	string str;
	s(t);
	while(t--)
	{
		int count=0;
		node* root=new node;
		root->data=char(1);
		root->size=1;
		temp=root;
		memset(&temp->child,0,sizeof(temp->child));
		s(n);
/*		for(i=0;i<n;i++)
		{
			scanf("%s",str[i]);		
		}*/
		for(i=0;i<n;i++)
		{
			temp=root;
			cin>>str;	l=str.length();
			for(j=0;j<l;j++)
			{
				k=(int)str[j]-'0';
				if(temp->child[k]==0)
				{
					if(temp->size>0)	count++;
					for(m=j;m<l;m++)
					{
						k=(int)str[m]-'0';
						temp->child[k]=new node;
						temp->size++;
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
	//	print(root);
	//	p(count);
		if(count==n)	printf("YES\n");	
		else			printf("NO\n");
	}

}
