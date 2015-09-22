#include<iostream>
#include<string.h>
using namespace std;
int bx[8][3]={{1,2,3},{1,4,7},{2,5,8},{3,6,9},{4,5,6},{7,8,9},{1,5,9},{3,5,7}};
bool owin(int *opos)
{
    for(int i=0;i<8;i++)
    {
      	if(opos[bx[i][0]-1]==1 && opos[bx[i][1]-1]==1 && opos[bx[i][2]-1]==1 )
      	return 1;
    }
    return 0;
}
bool xwin(int *xpos)
{
    for(int i=0;i<8;i++)
    {
      	if(xpos[bx[i][0]-1]==1 && xpos[bx[i][1]-1]==1 && xpos[bx[i][2]-1]==1 )
      	return 1;
    }
    return 0;
}
int main()
{
	int t,xpos[9]={0},opos[9]={0},i,xbox,obox;
	char a[9];
	bool flag=0;
	while(1)
	{
		memset(&xpos,0,sizeof(xpos));
		memset(&opos,0,sizeof(opos));
		xbox=0;   obox=0;
		for(i=0;i<9;i++)
		{
				 cin>>a[i]; 
				 if(a[i]=='d')		{	flag=1; break;		}
				 if(a[i]=='X')   {   xpos[i]=1;   xbox++;    }
		         if(a[i]=='O')   {   opos[i]=1;   obox++;    }
		} 
		//cout<<xbox<<"       "<<obox<<endl;   
		if(flag)	break;
	    if(xbox==obox  ||  xbox==obox+1)
	    {
	        if(owin(opos))
	        {
	        	if(xwin(xpos))
	        		cout<<"invalid\n";
	        	else if(xbox!=obox)
	        		cout<<"invalid\n";
	        	else 
	        		cout<<"valid\n";
	        }
	        else if(xwin(xpos))
	        	cout<<"valid\n";
	        else if(xbox+obox==9)
	        	cout<<"valid\n";
	        else
	        	cout<<"invalid\n";
	    }
	    else
	    	cout<<"invalid\n";
	}
}
