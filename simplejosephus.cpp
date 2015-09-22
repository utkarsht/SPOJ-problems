#include<iostream>
using namespace std;
int n;
struct ll
   {
   	int data;
	ll* next;
   }*head,*p,*p1;
	
void print(ll* p)
{
	for(int i=0;i<n;i++)
	{	cout<<p->data<<" -> ";
		p=p->next;
    }
}
int main()
{
	int i,j,t,pass;
	cout<<"Enter total members";
	cin>>n;
	head=new ll;
	head->data=1;
	head->next=0;
	p=head;
	for(i=2;i<=n;i++)
	{
	head->next=new ll;
	head=head->next;
	head->data=i;
	head->next=0;
	}
	head->next=p;
	cout<<"your list is\n";
	print(p);
	cout<<"enter paases";
	cin>>pass;
	pass--;
	head=p;
	t=n;
	for(i=0;i<t-1;i++)
	{
	    for(j=0;j<pass;j++)
	    {
	    	p1=p;
	    	p=p->next;
	    }
	    	p1->next=p->next;   delete p;
	    	p=p1->next;
	    	n--;
	    	cout<<endl;
	    	print(p);
	    	cout<<endl;
	}
}
