
#include <iostream>
#include<cstring>
#include<fstream>
using namespace std;
// Define a structure to store student information
struct Student {
    string name;
    int age;
    string section;
    string department;
    string fatherName;
    int id;
    string Gender;
};

// Function to add a studenta
void addStudent(Student* students, int& numStudents) {
    int numNewStudents;
    cout << "Enter the number of students to add: ";
    cin >> numNewStudents;
const int ID_SIZE = 8; // Size of the ID number
    // Generate a random integer between 10000 and 99999
   int randNum = rand() % 90000 + 10000;
    const int SECTION_CAPACITY = 15;
    int sectionCounters[3]={0,0,0};
    for (int i = 0; i < numNewStudents; i++) {
        cout << "Enter the name of the student: ";
        cin >> students[numStudents+i].name;
        cout << "Enter the father's name of the student: ";
        cin >> students[numStudents+i].fatherName;
       cout<<"Enter the Gender(M/F):";
        cin>> students[numStudents+i].Gender;
        cout << "Enter the age of the student: ";
        cin >> students[numStudents+i].age;
// Generate a random integer between 10000 and 99999
    int randNum = rand() % 90000 + 10000;
    // Convert the integer to a string and append it to the ID number
  students[numStudents+i].id += randNum;

        // Generate a section number for the student
        int sectionNumber = -1;
        for (int j = 0; j < 3; j++) {
            if (sectionCounters[j] < SECTION_CAPACITY) {
                sectionNumber = j + 1;
                sectionCounters[j]++;
                break;
            }
        }
        if (sectionNumber == -1) {
            cout << "Error: All sections are full." << endl;
            break;
        }
        students[numStudents+i].section = "CCS" + to_string(sectionNumber) + students[numStudents+i].name.substr(0, 1) + to_string(sectionCounters[sectionNumber-1])+ "/15";

        cout << "Enter the department name of the student: ";
        cin.ignore();
        getline(cin,students[numStudents+i].department);

    }

    numStudents += numNewStudents;

}

// Function to delete a student
void deleteStudent(Student* students, int& numStudents) {
    int idToDelete;
    cout << "Enter the ID of the student to delete: ";
    cin >> idToDelete;
    int indexToDelete = -1;
    for (int i = 0; i < numStudents; i++) {
        if (students[i].id == idToDelete) {
            indexToDelete = i;
            break;
        }
    }
    if (indexToDelete != -1) {
        // Shift all the elements after the deleted student back one position
        for (int i = indexToDelete; i < numStudents - 1; i++) {
            students[i] = students[i+1];
        }
        numStudents--;
        cout<<"****************************************************************"<<endl;
        cout << "Student with ID " << idToDelete << " has been deleted.\n";
        cout<<"****************************************************************"<<endl;
    } else {
        cout<<"****************************************************************"<<endl;
        cout << "No student with ID " << idToDelete << " was found.\n";
        cout<<"****************************************************************"<<endl;
    }
}
void updateStudent(Student* students, int numStudents) {
    int idToUpdate;
    cout << "Enter the ID of the student to update: ";
    cin >> idToUpdate;

    int indexToUpdate = -1;
    for (int i = 0; i < numStudents; i++) {
        if (students[i].id == idToUpdate) {
            indexToUpdate = i;
            break;
        }
    }

    if (indexToUpdate != -1) {
        // Ask the user to enter the updated information
        cout << "Enter student name: ";
        cin >> students[indexToUpdate].name;
        cout << "Enter father's name: ";
        cin >> students[indexToUpdate].fatherName;
        cout << "Enter gender (M/F): ";
        cin>> students[indexToUpdate].Gender;
        cout<< "Enter the department name of the student: ";
        cin.ignore();
        getline(cin,students[indexToUpdate].department);
        cout << "Enter age: ";
        cin >> students[indexToUpdate].age;
        cout << "Student information updated successfully!" << endl;
    } else {
        cout << "No student with ID " << idToUpdate << " was found." << endl;
    }
}

// Function to display a student
void displayStudent(Student* students, int numStudents)
 {
    if (numStudents == 0) {

        cout << "---->NO STUDENT FOUND." << endl;
    } else {
        cout<<"_______________________________________________________________________________________________________________________________"<<endl;
        cout << "Id\t\tNAME\t\tF.NAME\t\t\tGENDER\t\tSECTION\t\tDEPARTMENT\t\t\tAGE" <<endl;
        cout<<"_______________________________________________________________________________________________________________________________"<<endl;
             for (int i = 0; i < numStudents; i++)
            {

            cout <<"UU"<<students[i].id<<"R"<<"\t"<<students[i].name<<"\t\t"<<students[i].fatherName<<"\t\t\t"<<students[i].Gender<<"\t\t"<<students[i].section<<"\t"<<students[i].department<<"\t\t"<<students[i].age<< endl;

}

    }
}

void saveToFile(Student* students, int numStudents)
{
    ofstream outFile("students.txt");
    if (outFile.is_open())
    {
        for (int i = 0; i < numStudents; i++)
        {
            outFile <<"UU"<<students[i].id<<"R"<<"\t"<<students[i].name<<"\t\t"<<students[i].fatherName<<"\t\t\t"<<students[i].Gender<<"\t\t"<<students[i].section<<"\t"<<students[i].department<<"\t\t"<<students[i].age<< endl;
        }
        cout << "Student information saved to file successfully!" << endl;
        outFile.close();
    }
    else
    {
        cout << "Error opening file!" << endl;
    }
}
void readFromFile(Student* students, int numStudents)
{
    ifstream inFile("students.txt");
    if (inFile.is_open())
    {
        int i = 0;
        while (i < numStudents && inFile >> students[i].id >> students[i].name >> students[i].fatherName >> students[i].Gender >> students[i].section >> students[i].department >> students[i].age)
        {
            i++;
        }
        inFile.close();
        cout << "Student information read from file successfully!" << endl;
    }
    else
    {
        cout << "Error opening file!" << endl;
    }
}

// Function to generate a random integer between min and max
int main() {
    int index = 0; // Initialize index variable
    int choice, count = 0;
    const int MAX_STUDENTS = 100;
    Student students[MAX_STUDENTS];

    do {
        cout<<"_____________________________________"<<endl;
        cout<<"WELCOME TO  STUDENT MANAGEMENT SYSTEM"<<endl;
        cout<<"_____________________________________"<<endl;
        cout<<"1. Add student" << endl;
        cout<<"2. Delete student" << endl;
        cout<<"3. Display students" << endl;
        cout<<"4. Update" << endl;
        cout<<"5. Save To File Student Information"<<endl;
        cout<<"6. Read From Fille Student Information"<<endl;
        cout<<"7. Prepared By" << endl;
        cout<<"8. Exit" << endl;
        cout<<"Enter your choice: ";
        cin>> choice;
        switch (choice) {
            case 1:
                addStudent(students, count);
                break;
            case 2:
                deleteStudent(students, count);
                break;
            case 3:
                displayStudent(students, count);
                break;

            case 4:
                updateStudent(students, count);
                break;
            case 5:
                saveToFile(students,count);
                break;
            case 6:
                readFromFile(students,count);
                break;
                case 7:
                cout<<"****************************************************************"<<endl;
                cout<<"*BONSA TAKALE & BIRUK TARIKU                                   *"<<endl;
                cout<<"*SECTION:CCS1R1N3/14                                           *"<<endl;
                cout<<"*DEPARTMENT OF COMPUTER SCIENCE                                *"<<endl;
                cout<<"*                  SUBMISSION DATE: MARCH.2023                 *"<<endl;
                cout<<"*                  SUBMITTED TO: MR. KIDUS                     *"<<endl;
                cout<<"****************************************************************"<<endl;
                break;
                 case 8:
                cout<<"--------------------------------------------"<<endl;
                cout << "Exiting program." << endl;
                cout<<"--------------------------------------------"<<endl;
                break;
            default:
                cout<<"****************************************************************"<<endl;
                cout << "..........Invalid choice. Please try again.........." << endl;
                cout<<"****************************************************************"<<endl;
        }
    } while (choice != 8);

    return 0;
}

