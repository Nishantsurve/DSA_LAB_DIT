#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;
class Employee
{
private:
    int code;
    char name[20];
    float salary;

public:
    void read();
    void display();
    int getempcode()
    {
        return code;
    }
    int getsalary()
    {
        return salary;
    }
    void updatesalary(float s)
    {
        salary = s;
    }
};
void Employee::read()
{
    cout << "Enter empoyee code:";
    cin >> code;
    cout << "\nEnter name:";
    cin.ignore(1);
    cin.getline(name, 20);
    cout << "\nEnter salary:";
    cin >> salary;
}
void Employee::display()
{
    cout << code << "\t" << name << "\t" << salary << endl;
}
fstream file;
void deleteexistingfile()
{
    remove("EMPLOYEE.DAT");
}
void appendtofile()
{
    Employee x;
    x.read();
    file.open("EMPLOYEE.DAT", ios::binary | ios::app);
    if (!file)
    {
        cout << "Error in creating file\n";
        return;
    }
    file.write((char *)&x, sizeof(x));
    file.close();
    cout << "Record added successfully";
}
void displayAll()
{
    Employee x;
    file.open("EMPLOYEE.DAT", ios::binary | ios::in);
    if (!file)
    {
        cout << "ERROR IN OPENING FILE \n";
        return;
    }
    while (file)
    {
        if (file.read((char *)&x, sizeof(x)))

            x.display();
    }
    file.close();
}
void searchForRecord()
{
    Employee x;
    int c;
    int isFound = 0;
    cout << "Enter employee code: ";
    cin >> c;
    file.open("EMPLOYEE.DAT", ios::binary | ios::in);
    if (!file)
    {
        cout << "ERROR IN OPENING FILE \n";
        return;
    }
    while (file)
    {
        if (file.read((char *)&x, sizeof(x)))
        {
            if (x.getempcode() == c)
            {
                cout << "RECORD FOUND\n";
                x.display();
                isFound = 1;
                break;
            }
        }
    }
    if (isFound == 0)
    {
        cout << "Record not found!!!\n";
    }
    file.close();
}
void increaseSalary()
{
    Employee x;
    int c;
    int isFound = 0;
    float sal;
    cout << "enter employee code \n";
    cin >> c;
    file.open("EMPLOYEE.DAT", ios::binary | ios::in);
    if (!file)
    {
        cout << "ERROR IN OPENING FILE \n";
        return;
    }
    while (file)
    {
        if (file.read((char *)&x, sizeof(x)))
        {
            if (x.getempcode() == c)
            {
                cout << "Salary hike? ";
                cin >> sal;
                x.updatesalary(x.getsalary() + sal);
                isFound = 1;
                break;
            }
        }
    }
    if (isFound == 0)
    {
        cout << "Record not found!!!\n";
    }
    file.close();
    cout << "Salary updated successfully." << endl;
}
void insertRecord()
{
    Employee x;
    Employee newEmp;
    newEmp.read();
    fstream fin;
    file.open("EMPLOYEE.DAT", ios::binary | ios::in);
    fin.open("TEMP.DAT", ios::binary | ios::out);
    if (!file)
    {
        cout << "Error in opening EMPLOYEE.DAT file!!!\n";
        return;
    }
    if (!fin)
    {
        cout << "Error in opening TEMP.DAT file!!!\n";
        return;
    }
    while (file)
    {
        if (file.read((char *)&x, sizeof(x)))
        {
            if (x.getempcode() > newEmp.getempcode())
            {
                fin.write((char *)&newEmp, sizeof(newEmp));
            }
            // no need to use else
            fin.write((char *)&x, sizeof(x));
        }
    }
    fin.close();
    file.close();
    rename("TEMP.DAT", "EMPLOYEE.DAT");
    remove("TEMP.DAT");
    cout << "Record inserted successfully." << endl;
}
int main()
{
    char ch;
    deleteexistingfile();
    do
    {
        int n;
        cout << "ENTER CHOICE\n"
             << "1.ADD AN EMPLOYEE\n"
             << "2.DISPLAY\n"
             << "3.SEARCH\n"
             << "4.INCREASE SALARY\n"
             << "5.INSERT RECORD\n";
        cout << "Make a choice: ";
        cin >> n;
        switch (n)
        {
        case 1:
            appendtofile();
            break;
        case 2:
            displayAll();
            break;
        case 3:
            searchForRecord();
            break;
        case 4:
            increaseSalary();
            break;
        case 5:
            insertRecord();
            break;
        default:
            cout << "Invalid Choice\n";
        }
        cout << "Do you want to continue ? : ";
        cin >> ch;
    } while (ch == 'Y' || ch == 'y');
    return 0;
}