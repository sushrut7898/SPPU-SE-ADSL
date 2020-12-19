#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
class student
{
	int roll_no;
	char name[25];
	char div[10];
	public:
		void accept()
		{
				cout<<"\n\tEnter the Name of the student:";
				cin>>name;
				
				cout<<"\n\tEnter the Division of the student:";
				cin>>div;
				
				cout<<"\n\tEnter the Roll Number of the student:";
				cin>>roll_no;
		}
		
		void display()
		{
			cout<<setw(5)<<"Name"<<setw(15)<<"Division"<<setw(15)<<"Roll No \n";
			cout<<setw(5)<<name;
			cout<<setw(15)<<div;
			cout<<setw(15)<<roll_no;
		}	
		
		void file_read()
		{
			fstream f1;
         	student s1;
	        int n;	
			f1.open("abhi.dat",ios::out);
			cout<<"\n\tHow many Records you want to display";
			cin>>n;
	for(int i=0;i<n;i++)
	{
		s1.accept();
		f1.write((char *)&s1,sizeof(s1));
	}
	    f1.close();
		}
		
		void file_write()   //read
		{
			fstream f1;
			student s1;
			cout<<"\n\tThe Records Written on to the file are:";
			cout<<endl;
			f1.open("abhi.dat",ios::in);
			f1.read((char *)&s1,sizeof(s1));
			while(f1)
			{
				s1.display();
				f1.read((char *)&s1,sizeof(s1));
			}
			f1.close();
		}
		
		int validate(int no)
		{
			if(roll_no==no)
			return 1;
			else
			return 0;
		}
		
		void modify_record()
		{
			int no;
			student s1;
			fstream f1;
			f1.open("abhi.dat",ios::in|ios::out);
			cout<<"\n\tEnter the record to modify";
			cin>>no;
			int flag=0;
			int count=0;
			f1.read((char *)&s1,sizeof(s1));
			while(f1)
			{
			flag=s1.validate(no);
			if(flag==1)
			{
				break;
			}
			else
			{
				count++;
				f1.read((char *)&s1,sizeof(s1));
			}
		    }
		    
		    if(flag==1)
		    {
		    	cout<<"\n\tRecord Found in the File!!!";
				cout<<"\n\tNow Enter New Records";
				s1.accept();
				f1.seekp(count*sizeof(s1),ios::beg);
				f1.write((char *)&s1,sizeof(s1));
				cout<<"\n\tModified With Success!!!";
			}
			
			else
			{
				cout<<"\n\tThe Record was Not Foud in the File";
			}
	}
	
	    void del()
	    {
	    	fstream f1,f2;
	    	student s1;
	    	int no;
	    	int flag=0;
	    	int count=0;
	    	f1.open("abhi.dat",ios::in);
	    	f2.open("Test.dat",ios::out);
	    	cout<<"\n\tEnter the record to Delete:";
	    	cin>>no;
	    	f1.read((char *)&s1,sizeof(s1));
	    	while(f1)
	    	{
	    		flag=s1.validate(no);
	    		if(flag==0)
	    		{
	    			f2.write((char *)&s1,sizeof(s1));
				}
					f1.read((char *)&s1,sizeof(s1));
			}
			f1.close();
			f2.close();
			remove("abhi.dat");
			rename("Test.dat","abhi.dat");
	}
};

int main()
{
	int ch;
	student s1;
	do
	{
	cout<<"\n\tMENU";
	cout<<"\n\t1.INSERT RECORD ONTO THE FILE";
	cout<<"\n\t2.DISPLAY RECORDS OF THE FILE";
	cout<<"\n\t3.MODIFY RECORDS OF THE FILE";
	cout<<"\n\t4.DELETE RECORDS OF THE FILE";
	cout<<"\n\t5.EXIT";
	cout<<"\n\tEnter your choice:";
	cin>>ch;
	
	switch(ch)
	{
		case 1:
			s1.file_read();
			break;
			case 2:
				s1.file_write();
				    break;
				    case 3:
					s1.modify_record();
					break;
					case 4:
					s1.del();
					break;
				    case 5:
					cout<<"\n\tTHANK YOU";
					break;
	 } 
}while(ch!=5);
}

