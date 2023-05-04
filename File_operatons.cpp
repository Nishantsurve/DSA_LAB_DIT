#include<iostream>
#include<fstream>
using namespace std;

class Student{
    public:
    int rno;
    char name[30], address[50];
    char div;

    void setdata(){
        cout<<"\nEnter the name of Student = ";
        cin>>name;
        cout<<"\nEnter the Roll No. of Student = ";
        cin>>rno;
        cout<<"\nEnter the Division of Student = ";
        cin>>div;
        cout<<"\nEnter the Address of Student = ";
        cin>>address;
    }
    void getdata(){
        cout<<"\nName = "<<name;
        cout<<"\nRoll No. = "<<rno;
        cout<<"\nDivision = "<<div;
        cout<<"\nAddress = "<<address;
    }
    int getRollNo(){
        return rno;
    }
};

void writedata(){
    ofstream fout;
    fout.open("Student.dat", ios::binary| ios::app);

    Student s;
    s.setdata();
    fout.write((char*)&s, sizeof(s));

    fout.close();
}

void displayfile(){
    ifstream fin;
    fin.open("Student.dat", ios::binary);
    Student s;
    
    while(fin.read((char*)&s, sizeof(s))){
        cout<<"\n";
        s.getdata();
    }
    fin.close();
}
void searchdata(int key){
    ifstream fin;
    fin.open("Student.dat", ios::binary);
    Student s;
    
    int flag=0;
    while(fin.read((char*) &s, sizeof(s))){
        if(s.getRollNo() == key){
            s.getdata();
            flag=1;
            break;
        }
    }
    if(flag==0){
        cout<<"\nData not found";
    }
}

void deletedata(int key){
    ifstream fin;
    fin.open("Student.dat", ios::binary);
    ofstream fout;
    fout.open("temp.dat", ios::out | ios::binary);
    Student s;
    int flag=0;
    while(fin.read((char*) &s, sizeof(s))){
        if(s.getRollNo() != key){
            fout.write((char*)&s, sizeof(s));
           
        }
         flag = 1;
    }
    if(flag==1){
        cout<<"\nData Deleted "<<endl;
        }
        else{
            cout<<"Data not found"<<endl;
        }
        
    fin.close();
    fout.close();
    remove("Student.dat");
    rename("temp.dat", "Student.dat");
}

int main(){
    int ch;
    do{
        cout<<"\n1.Write into file \n2.Display\n3.Search\n4.Delete\n5.Exit\n";
        cout<<"\nEnter your choice= ";
        cin>>ch;
        switch(ch){
            case 1:
                writedata();
                break;
            case 2:
                displayfile();
                break;
            case 3:
                int key;
                cout<<"\n\nEnter the Roll No to be searched = ";
                cin>>key;
                searchdata(key);
                break;
            case 4:
                int val;
                cout<<"\n\nEnter the Roll No to be deleted = ";
                cin>>val;
                deletedata(val);
                break;
            case 5:
                cout<<"\n\nExited";
                exit(0);
        }
    }while(ch<=5);
return 0;
}
