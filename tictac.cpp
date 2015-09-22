#include<iostream>
#include<windows.h>
using namespace std;
void gotoxy(short x, short y) {
COORD pos = {x, y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

#define prth  cout<<"----------------";
void prtv(int a,int b)  {
for(int j=1;j<11;j++)  { gotoxy(a,b);   cout<<"|";  b++; }  }
bool fnd(int a,int *b,int c) {   for(int i=0;i<c;i++) { if(*(b+i)==a) { return 1;} } return 0;  }
int main()
{
    char ch='*';
   int bx[8][3]={{1,2,3},{1,4,7},{2,5,8},{3,6,9},{4,5,6},{7,8,9},{1,5,9},{3,5,7}};
    int ok=0,n,i,j,k,a,b,s,xbox[9]={0},zbox[9]={0},m=0,p=0,q,w=0;
   gotoxy(24,10);
   prth
   gotoxy(24,13);
   prth
   prtv(28,7);
   prtv(34,7);
   while(1)
   {
   	gotoxy(22,18);    cout<<"                                    ";  gotoxy(22,18); 
   	cout<<ch<<"  enter your position      ";
   	cin>>n;  if(n<1  ||  n>9) 
   	{gotoxy(22,18);  cout<<"wrong choice";    continue;  }
   	if(fnd(n,xbox,m))  continue;
   	if(fnd(n,zbox,p))  continue;
   	k=n%3;    if(k==0)  a=36;  if(k==1)   a=26;    if(k==2)  a=31;
   	if(n<=3)  b=9;  else if(n<=6)   b=12;   else  b=15;
   	gotoxy(a,b) ;  cout<<ch;
   	if(ch=='*')   {  xbox[m++]=n;  ch='0';/* gotoxy(0,0); for(q=0;q<m;q++)   cout<<xbox[q];*/ }
   	else     {    zbox[p++]=n; ch='*'; /*gotoxy(0,0); for(q=0;q<m;q++)   cout<<zbox[q];*/ }
   	
   		   for(s=0;s<8;s++)
			  {  
			      if(  fnd(bx[s][0],xbox,m) &&  fnd(bx[s][1],xbox,m) &&  fnd(bx[s][2],xbox,m)   )
			      {    gotoxy(22,18);   cout<<"                                  ";  gotoxy(22,18);   cout<<'*'<<"   won ";   ok=1;  break;  }
			      if(  fnd(bx[s][0],zbox,n) &&  fnd(bx[s][1],zbox,n) &&  fnd(bx[s][2],zbox,n)   )
			      {    gotoxy(22,18);   cout<<"                                  ";  gotoxy(22,18);   cout<<'0'<<"   won ";   ok=1;  break; }
			  } 
			  w++;
			  gotoxy(0,0);  cout<<w;
   if(w==9 )	  {      gotoxy(22,18);   cout<<"                                  ";  gotoxy(22,18);   cout<<"khichadi pak gai";   }
   	      if(ok==1)    
		  {	 break;   } 	
   }
   gotoxy(22,20);   cout<<"game  ended";
   return  0;
}
