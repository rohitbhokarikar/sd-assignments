#include <iostream>
#include<fstream>
#include<cstring>
#include<iomanip>
#include <cstdlib>
using namespace std;
const int MAX=30;
class Student
{
    int rollno;
    char name[20];
    char div;
    public:
    Student()
    {
        strcpy(name,"");
        rollno=div=0;
    }
    Student(int rollno,char name[MAX],int year,char div,char address[MAX])
    {
        strcpy(this->name,name);
        this->rollno=rollno;
        this->div=div;
    }
    int getRollNo()
    {
        return rollno;
    }
    void displayRecord()
    {
        cout<<endl<<setw(5)<<rollno<<setw(20)<<name<<setw(5)<<setw(5)<<div<<setw(10);
    }
};
class FileOperations
{
    fstream file;
    public:
    FileOperations(char* filename)
    {
        file.open(filename,ios::in|ios::out|ios::ate|ios::binary);
    }
    void insertRecord(int rollno, char name[MAX],int year, char div,char city[MAX])
    {
        Student s1(rollno,name,year,div,city);
        file.seekp(0,ios::end);
        file.write((char *)&s1,sizeof(Student));
    }
    void displayRecord(int rollNo)
    {
            Student s1;
            file.seekg(0,ios::beg);
            bool flag=false;
            while(file.read((char*)&s1,sizeof(Student)))
            {
                if(s1.getRollNo()==rollNo)
                {
                    s1.displayRecord();
                    flag=true;
                    break;
                }
            }
            if(flag==false)
            {
                cout<<"\nRecord of "<<rollNo<<"is not present.";
            }
}
void deleteRecord(int rollno)
{
    ofstream outFile("new.dat",ios::binary);
    file.seekg(0,ios::beg);
    bool flag=false;
    Student s1;
    while(file.read((char *)&s1, sizeof(Student)))
    {
            if(s1.getRollNo()==rollno)
            {
                flag=true;
                continue;
            }
    outFile.write((char *)&s1, sizeof(Student));
    }
    if(!flag)
    {
        cout<<"\nERROR...... Record is not present.";
    }
    file.close();
    outFile.close();
    remove("student.dat");
    rename("new.dat","student.dat");
    file.open("student.dat",ios::in|ios::out|ios::ate|ios::binary);
}
};
int main()
{
    system("COLOR FC");
    system("cls");
    ofstream newFile("student.dat",ios::app|ios::binary);
    newFile.close();
    FileOperations file((char*)"student.dat");
    int rollNo,year,choice=0;
    char div;
    char name[MAX],address[MAX];
    while(choice!=4)
    {
         cout<<"\n======================MENU===================\n";
         cout<<"\n1.Add Record\n2.Display Record of specific person\n3.Delete a record \n";
         cout<<"\n=============================================\n";
         cout<<"\nEnter your choice  - \n";
         cin>>choice;
         switch(choice)
         {
             case 1 :
                 {
                    cout<<"\nEnter RollNo & Name - \n";
                    cin>>rollNo>>name;
                    cout<<"\nEnter Division -  \n";
                    cin>>div;
                    cout<<"\nEnter address  - \n";
                    cin>>address;
                    file.insertRecord(rollNo,name,year,div,address);
                    cout<<"\nRecord Inserted - Sucess";
                    break;
                 }
             case 2 :
                 {
                    cout<<"\nEnter Roll Number -";
                    cin>>rollNo;
                    file.displayRecord(rollNo);
                    break;
                 }
             case 3:
                 {
                    cout<<"\nEnter RollNo -";
                    cin>>rollNo;
                    file.deleteRecord(rollNo);
                    break;
              }
        }
   }
 return 0;
}
