#include<iostream>
#include<fstream>
using namespace std;
class student
{
	public:
	char name[30];
	int roll;
	float cgpa;
	friend istream& operator>>(istream& in,student& s)
	{
		in>>s.name>>s.roll>>s.cgpa;
		return in;
	}
	friend ostream& operator<<(ostream& out,student& s)
	{
		out<<"      Name    "<<s.name<<"        Roll       "<<s.roll<<"     Cgppa       "<<s.cgpa<<endl;
		return out;
	}
};

int main()
{
	student s;
	char buffer[30];
	fstream f("file.txt");
	fstream f2("file2.txt");
	int n,i;
	cout<<"How many details you want\n";
	cin>>n;
	cout<<"Now Enter the details of students\n";
	for(i=0;i<n;i++)
    {	cin>>s;     f<<s;    }
    f.seekp(0,ios::beg);
    for(i=0;i<n;i++)
    {
    	f.getline(buffer,30);
    	cout<<buffer<<endl;
    }
    f.close();

}
