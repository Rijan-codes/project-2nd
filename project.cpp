#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
const int MAX_students = 48;
class students
{
public:
    char name[50];
    int roll;
    float marks;

    void set()
    {
        cin.ignore();
        cout << "Enter the name of student: ";
        cin.getline(name, 50);
        cout << "Enter roll number: ";
        cin >> roll;
        cout << "Enter marks: ";
        cin >> marks;
    }
    void display()
    {
        cout << "Name: " << name << endl
             << "Roll_no: " << roll << endl
             << "Marks: " << marks << endl;
    }
};
class Student_management
{
    students number[MAX_students];
    int count;

public:
    Student_management()
    {
        count = 0;
    }
    int login()
    {
        char username[30];
        char password[30];
        cout << "Username: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;
        if (strcmp(username, "KHEC") == 0 && strcmp(password, "BEcompKHEC") == 0)
        {
            cout << "login successful!"<<endl<<endl;
            return 1;
        }
        else
        {
            cout << "incorrect credentials!" << endl;
            cout << "Please try again" << endl<<endl;
            return 0;
        }
    }
    void loadonfile()
    {
        ifstream fin("record.txt");
        if (fin)
        {
            count = 0;
            {

                while (count < MAX_students && fin >> number[count].roll)
                {
                    fin.ignore();
                    fin.getline(number[count].name, 50);
                    fin >> number[count].marks;
                    fin.ignore();
                    count++;
                }
            }
        }
        fin.close();
    }
    void saveonfile()
    {
        ofstream fout("record.txt");
        for (int i = 0; i < count; i++)
        {
            fout << number[i].roll << endl;
            fout << number[i].name << endl;
            fout << number[i].marks << endl;
        }
        fout.close();
    }
    void addStudent()
    {
        if (count < MAX_students)
        {
            number[count].set();
            count++;
            cout << "Student registered in the list successfully!"<<endl<<endl;
        }
        else
        {
            cout << "Registration failed!" << endl;
            cout << "Required students are already added" << endl;
        }
    }
    void displayRecords()
    {
        if (count == 0)
        {
            cout << "No data recorded" << endl;
        }
        for (int i = 0; i < count; i++)
        {
            cout << "||==students==||" << endl
                 << endl;
            number[i].display();
        }
    }
    void searchRecord()
    {
        int rollsearch;
        cout << "Enter the Roll_number of student you like to search: ";
        cin >> rollsearch;
        for (int i = 0; i < count; i++)
        {
            if (number[i].roll == rollsearch)
            {
                cout << "---Student found!!---" << endl
                     << endl;
                number[i].display();
                return;
            }
        }
        cout << "---Student not found!!---" << endl;
    }
    void changes()
    {
        int changing_roll;
        cout << "Enter the roll number: ";
        cin >> changing_roll;
        for (int i = 0; i < count; i++)
        {
            if (number[i].roll == changing_roll)
            {
                cout << "Enter the changes for roll_number: " << changing_roll;
                number[i].set();
                cout << "---changes made successful!---" << endl;
            }
        }
        cout << "---NO student with such credentials found!---" << endl;
    }
    void deleteStudent()
    {
        int deleting_roll;
        cout << "Enter the roll_number to be deleted: ";
        cin >> deleting_roll;
        for (int i = 0; i < count; i++)
        {
            if (number[i].roll == deleting_roll)
            {
                number[i] = number[i - 1];
                cout << "---Information deleted successfully!---" << endl;
            }
            cout << "---Student not found!---" << endl;
        }
    }
    void sortbyRoll()
    {
        for (int i = 0; i < count - 1; i++)
        {
            for (int j = 0; j < count - 1 - i; j++)
            {
                if (number[j].roll > number[j + 1].roll)
                {
                    students temp = number[j];
                    number[j] = number[j + 1];
                    number[j + 1] = temp;
                }
            }
        }
        cout << "---Students according to roll_number---" << endl
             << endl;
    }
    void sortbyMarks()
    {
        for (int i = 0; i < count - 1; i++)
        {
            for (int j = 0; j < count - 1 - i; j++)
            {
                if (number[j].marks > number[j + 1].marks)
                {
                    students temp = number[j];
                    number[j] = number[j + 1];
                    number[j + 1] = temp;
                }
            }
        }
        cout << "---Students according to marks---" << endl
             << endl;
    }
};

int main()
{
    Student_management manipulator;
    if (!manipulator.login())
        return 0;

    manipulator.loadonfile();
    int choice;
    do
    {
        cout << "||=== STUDENTS RECORD MANAGEMENT SYSTEM ===||" << endl
             << endl;
        cout << "--Press '1' to Add student--" << endl;
        cout << "--Press '2' to display all students--" << endl;
        cout << "--Press '3' to search record of student--" << endl;
        cout << "--Press '4' to make changes on record of student--" << endl;
        cout << "--Press '5' to delete information of student--" << endl;
        cout << "--Press '6' to sort list by Roll_number--" << endl;
        cout << "--Press '7' to sort list by Marks--" << endl;
        cout << "--Press '8' to save record on file--" << endl;
        cout << "---Enter your choice---" << endl;
        cin >> choice;

        if (choice == 1)
        {
            manipulator.addStudent();
        }
        else if (choice == 2)
        {
            manipulator.displayRecords();
        }
        else if (choice == 3)
        {
            manipulator.searchRecord();
        }
        else if (choice == 4)
        {
            manipulator.changes();
        }
        else if (choice == 5)
        {
            manipulator.deleteStudent();
        }
        else if (choice == 6)
        {
            manipulator.sortbyRoll();
        }
        else if (choice == 7)
        {
            manipulator.sortbyMarks();
        }
        else if (choice == 8)
        {
            manipulator.saveonfile();
            cout << endl
                 << "Data saved successfully!" << endl;
            cout << "Exiting...." << endl<<endl;
        }
        else
        {
            cout << "---Invalid Input!---" << endl;
        }
    } while (choice != 8);

    return 0;
}
