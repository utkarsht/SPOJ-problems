#include<iostream>
using namespace std;
struct ll
		{
		int data;
		ll* next;
		ll* pre;
	    };
	    ll* head;
	    ll* p;
void print()
		{		
			head=head->next;   p=head; int flag=1;
			while(!(p==head) || flag)
			{  
			   cout<<p->data<<"  ->  ";
			   p=p->next;
			   flag=0;
		    }
			p=head;	
	    /*		while(p->next->next!=head)
			{  
			cout<<endl;
			   cout<<p->pre->data<<"  <-  "<<p->data<<"  ->  "<<p->next->data<<endl;
			   p=p->next;
		    }*/
		}
		void printpre()
		{
			p=head; int flag=1;
			while(!(p==head) || flag)
		{		cout<<p->data<<"  ->  ";
			   p=p->pre;
			   flag=0;
			}
		}
		void add(int d)
		{
			p=head;
			while(p->next!=head)
			p=p->next;
			p->next=new ll;
			p->next->pre=p;
			p=p->next;
			p->data=d;
			p->next=head;
			head->pre=p;
		}
			void del(int k)
		{
			p=head;
			if(k==1)
			{
				head->next->pre=head->pre;
				head->pre->next=head->next;
				head=head->next;
			}
			else
			{
			for(int i=0;i<k-2;i++)
				p=p->next;
		    p->next=p->next->next;
		    p=p->next;
		    p->pre=p->pre->pre;
		    //cout<<p->data<<" data \n";
		    }
		}
		int josephus(int k)
		{
			k++; int j=3;
			ll *t;
			t=head;
			while(j--)
			{
			for(int i=0;i<k-2;i++)
			{
			t=t->next;
		    }
		    t->next=t->next->next;
		    t=t->next;
		    t->pre=t->pre->pre; 
		    print();    cout<<"   next\n";
		    printpre(); cout<<"   pre\n";
		    }
			return t->data;
		}
int main()
{
                int ch,d,k=5,flag=1;
                while(k--)
                {
 		        if(flag)
			    {
 		        cout<<"enter data";
			    cin>>d;
			    head=new ll;
			    head->data=d;
			    head->next=head;
			    head->pre=head;
		        cout<<"enter data";
			    cin>>d;
			    p=new ll;
			    p->data=d;
			    head->next=p;
			    head->pre=p;
			    p->next=head;
			    p->pre=head;
				flag=0;
				}
			    else
				{
			    	cout<<"enter data";
			    	cin>>d;
			    add(d);
		     	}  }
			    print(); cout<<endl;
			    printpre();
			    cout<<endl;
			    cout<<"enter passes";
			    cin>>k;
			    del(k);
			   cout<<josephus(k);
			     print();
			    printpre();
}

