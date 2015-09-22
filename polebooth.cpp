#include<iostream>
#include<cstring>
using namespace std;
int i;
class polebooth
{
	char name[10][20];
	int count[10];
	int vote[4];
	public:
		void putname(int n)
		{for(i=0;i<n;i++)  cin>>name[i];
		}
		char* getname(int k){return name[k];
		}
		int getvote(int i) {return vote[i];
		}
		int getcount(int j) {return count[j];
		}
		void setcount(){for(i=0;i<4;i++)  count[i]=0;
		}
		void ivote(int k){ vote[k]++;
		}
		int getwin(){int max=vote[0],k;
		for(i=1;i<4;i++){if(vote[i]>max) {max=vote[i]; k=i;
		}
		}
		return k;
		}
		float votepercent(int n){int total=0;
		for(i=0;i<4;i++)  total+=vote[i];   return ((float) total*100/n);
		}
	
}pb;
int main()
{int n,k;
int choice;
char voter[10];
char mark;
cout<<"enter total voter\n";
cin>>n;
pb.setcount();
cout<<"enter name in voter id list\n";
pb.putname(n);
cout<<"leaders with their election marks are\n";
cout<<"  l1  +  l2  -   l3  *    l4  /";
cout<<"menu :\n 1.cast vote\n  2. display \n 3.exit\n";
cout<<"enter your choice";
cin>>choice;
switch(choice)
{case 1:
	
	
	do{
		cout<<"enter your name";
		cin>>voter;
		for(i=0;i<n;i++){k=strcmp(voter,pb.getname(i));  if(k==0) break;
		}
		if(i==n)  cout<<"name does not exist in list\n";
		if(pb.getcount(i)==1)  cout<<"you have given your vote before";
	}
	while(k==n  ||  pb.getcount(i)==1);
	cout<<"enter election mark";
	cin>>mark;
	if(mark=='+')  pb.ivote(0);
	else if(mark =='-')pb.ivote(1);
	else if(mark=='*')pb.ivote(2);
	else if(mark=='/')pb.ivote(3);
	else cout<<"invalid";
	break;
case 2:
	cout<<"votes to condidates are";
	for(i=0;i<4;i++)cout<<"leader"<<i<<"got"<<pb.getvote(i)<<"votes\n";
	cout<<"\n winner is"<<pb.getwin();
	cout<<"vote percent"<<pb.votepercent(n);
	break;
	case 3:
		break;
	
}
}

