#include<iostream>
#include<fstream>
#include<iomanip>
 
using namespace std;
 
 
 
class student
{
	int idnum;
	char name[50];
	char a[30], b[30], c[30], d[30], e[30] ,f[30];
	public:
	void getdata();		
	void showdata() const;	
	void show_tabular() const;
	int getIDNum() const;
}; 
 
 
 
void student::getdata()
{
	cout<<"\nEnter The serial no of day ";
	cin>>idnum;
	cout<<"\n\nEnter day: ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\n9:30-10:20: ";
	
	cin.getline(a,30);
	cout<<"\n10:30-11:20: ";
	
	cin.getline(b,30);
	cout<<"\n11:30-12:20: ";
	
	cin.getline(c,30);
	cout<<"\n1:00-2:00: ";
	
	cin.getline(d,30);
	cout<<"\n2:00-3:00: ";
	
	cin.getline(e,30);
	cout<<"\n3:00-4:00: ";
	
	cin.getline(f,30);
	}
 
void student::showdata() const
{
	cout<<"\nserial no: "<<idnum;
	cout<<"\nday: "<<name;
	cout<<"\n9:30-10:20: "<<a;
	cout<<"\n10:30-11:20: "<<b;
	cout<<"\n11:30-12:20: "<<c;
	cout<<"\n1:00-2:00: "<<d;
	cout<<"\n2:00-3:00: "<<e;
    cout<<"\n3:00-4:00: "<<e;	
}
 
void student::show_tabular() const
{
	cout<<idnum<<setw(6)<<" "<<name<<" "<<setw(10)<<a<<setw(4)<<" "<<b<<setw(4)<<" "<<c<<setw(4)
		<<" "<<d<<setw(4)<<" "<<e<<setw(8)<<" "<<f<<setw(6)<<endl;
}
 
int  student::getIDNum() const
{
	return idnum;
}
void SaveStudent();	
void displayAll();	
void Searchdisplay(int);	
void modifyStudent(int);	
void deleteStudent(int);	
void DisplayClassResult();	
void DisplayResult();			
	
 
 
 
 
void write_student()
{
	student st;
	ofstream outFile;
	outFile.open("new.dat",ios::binary|ios::app);
	st.getdata();
	outFile.write(reinterpret_cast<char *> (&st), sizeof(student));
	outFile.close();
    	cout<<"\n\nroutine record Has Been Created ";
	cin.ignore();
	cin.get();
}
 
 
 
void display_all()
{
	student st;
	ifstream inFile;
	inFile.open("new.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}
	cout<<"\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n";
	while(inFile.read(reinterpret_cast<char *> (&st), sizeof(student)))
	{
		st.showdata();
		cout<<"\n\n====================================\n";
	}
	inFile.close();
	cin.ignore();
	cin.get();
}
 
 
 
void display_sp(int n)
{
	student st;
	ifstream inFile;
	inFile.open("new.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}
	bool flag=false;
	while(inFile.read(reinterpret_cast<char *> (&st), sizeof(student)))
	{
		if(st.getIDNum()==n)
		{
	  		 st.showdata();
			 flag=true;
		}
	}
	inFile.close();
	if(flag==false)
		cout<<"\n\nrecord not exist";
	cin.ignore();
	cin.get();
}
 
 
void modify_student(int n)
{
	bool found=false;
	student st;
	fstream File;
	File.open("new.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}
    	while(!File.eof() && found==false)
	{
 
		File.read(reinterpret_cast<char *> (&st), sizeof(student));
		if(st.getIDNum()==n)
		{
			st.showdata();
			cout<<"\n\nPlease Enter The New Details of student"<<endl;
			st.getdata();
		    	int pos=(-1)*static_cast<int>(sizeof(st));
		    	File.seekp(pos,ios::cur);
		    	File.write(reinterpret_cast<char *> (&st), sizeof(student));
		    	cout<<"\n\n\t Record Updated";
		    	found=true;
		}
	}
	File.close();
	if(found==false)
		cout<<"\n\n Record Not Found ";
	cin.ignore();
	cin.get();
}
 
 
 
void delete_student(int n)
{
	student st;
	ifstream inFile;
	inFile.open("new.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}
	ofstream outFile;
	outFile.open("T.dat",ios::out);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&st), sizeof(student)))
	{
		if(st.getIDNum()!=n)
		{
			outFile.write(reinterpret_cast<char *> (&st), sizeof(student));
		}
	}
	outFile.close();
	inFile.close();
	remove("new.dat");
	rename("T.dat","new.dat");
	cout<<"\n\n\tRecord Deleted ..";
	cin.ignore();
	cin.get();
}
 
 
void class_result()
{
	student st;
	ifstream inFile;
	inFile.open("new.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}
	cout<<"\n\n\t\tclass routine \n\n";
	cout<<"====================================================================================================\n";
	cout<<"seral id     day |  9:30-10:20|   10:30-11:20| 11:30-12:20| 1:00-2:00| 2:00-3:00   | 3:00-4:00  |"<<endl;
	cout<<"===================================================================================================\n";
	while(inFile.read(reinterpret_cast<char *> (&st), sizeof(student)))
	{
		st.show_tabular();
	}
	cin.ignore();
	cin.get();
	inFile.close();
}
 
 
 
 
int main()
{
	char ch;
	int num;
	cout.setf(ios::fixed|ios::showpoint);
	cout<<setprecision(2); 
	do
	{
	system("cls");
	cout<<"\t@*@*@*@*@*@*@*@*@*@*@*@*@*@*@*@*@*@*@*@*@*@*@*@*@*";
	cout<<"\n\n\t1.CREATE CLASS ROUTINE";
	cout<<"\n\n\t2.DISPLAY ALL ROUTINES IN COLUMN MODE";
	cout<<"\n\n\t3.SEARCH DAY ";
	cout<<"\n\n\t4.MODIFY ROUTINE";
	cout<<"\n\n\t5.DELETE CLASS";
	cout<<"\n\n\t6. DISPLAY CLASS ROUTINE";
	cout<<"\n\n\t7. EXIT";
	cout<<"\n\n\t@*@*@*@*@*@*@*@*@*@*@*@*@*@*@*@*@*@*@*@*@*@*@*@*@*@";
	cout<<"\n\n\tPlease Enter Your Choice (1-7): ";
	cin>>ch;
	system("cls");
	switch(ch)
	{
	case '1':	write_student(); break;
	case '2':	display_all(); break;
	case '3':	cout<<"\n\n\tPlease Enter day serial id: "; cin>>num;
				display_sp(num); break;
	case '4':	cout<<"\n\n\tPlease EEnter day serial id: "; cin>>num;
			modify_student(num);break;
	case '5':	cout<<"\n\n\tPlease Enter day serial id: "; cin>>num;
			delete_student(num);break;
	case '6' :	class_result(); break;
	case '7':	exit(0);;
	default:	cout<<"\a"; 
		
    }
	}while(ch!='7');
 
	return 0;
}
