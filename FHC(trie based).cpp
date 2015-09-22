#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
using namespace std;

#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])
 
#define ALPHABET_SIZE (26)
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
 
// trie node
typedef struct trie_node trie_node_t;
struct trie_node
{
    int value;
    trie_node_t *children[ALPHABET_SIZE];
};
 
// trie ADT
typedef struct trie trie_t;
struct trie
{
    trie_node_t *root;
    int count;
};
 
trie_node_t *getNode(void)
{
    trie_node_t *pNode = NULL;
 
    pNode = (trie_node_t *)malloc(sizeof(trie_node_t));
 
    if( pNode )
    {
        int i;
 
        pNode->value = 0;
 
        for(i = 0; i < ALPHABET_SIZE; i++)
        {
            pNode->children[i] = NULL;
        }
    }
 
    return pNode;
}
 
// Initializes trie (root is dummy node)
void initialize(trie_t *pTrie)
{
    pTrie->root = getNode();
    pTrie->count = 0;
}
 
// If not present, inserts key into trie
// If the key is prefix of trie node, just marks leaf node
int ans;

void insert(trie_t *pTrie, char key[])
{
    int level;
    int length = strlen(key);
    int index;
    trie_node_t *pCrawl;
 
    pTrie->count++;
    pCrawl = pTrie->root;
 
    for( level = 0; level < length; level++ )
    {
        index = CHAR_TO_INDEX(key[level]);
        if( !pCrawl->children[index] )
        {
            pCrawl->children[index] = getNode();
        }
 		else
 		{
 			ans++;
 		}
        pCrawl = pCrawl->children[index];
    }
 
    // mark last node as leaf
    pCrawl->value = pTrie->count;
}
 

// Driver
int main()
{
    trie_t trie;
  //  fstream fin("E://autocomplete.txt");
  //  fstream fout("E://autocomplete_out.txt");
    char str[1000000];
    int t,n,sum;
    cin>>t;
    for(int j=1;j<=t;j++)
	{
	    initialize(&trie);	
	    sum = 0;
	    cin>>n;
	    while(n--)
		{
			cin>>str;
			ans = 0;
			insert(&trie,str);
			ans++;
			if(ans>strlen(str))
				ans = strlen(str);
			sum += (ans);
		}	
		cout<<"Case #"<<j<<": "<<sum<<endl;
	}
    return 0;
}
