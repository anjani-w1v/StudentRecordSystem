#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct Student {
    string name;
    int rollNo;
    float marks;
};

vector<Student> students;  // store all students

void addStudent(){
    Student s;
    cout << "Enter name: ";
    cin >> s.name;
    cout << "Enter roll number: ";
    cin >> s.rollNo;
    cout << "Enter marks: ";
    cin >> s.marks;
    students.push_back(s);
    cout << "Student added successfully!" << endl;
}

void displayAll(){
    if(students.empty()){
        cout << "No students yet!" << endl;
        return;
    }
    cout << "\n--- All Students ---" << endl;
    for(auto s : students){
        cout << "Name: " << s.name
             << " | Roll: " << s.rollNo
             << " | Marks: " << s.marks << endl;
    }
}

int main(){
    int choice;
    do {
        cout << "\n=== Student Record System ===" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Display All" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice){
            case 1: addStudent(); break;
            case 2: displayAll(); break;
            case 3: cout << "Goodbye!" << endl; break;
            default: cout << "Invalid choice!" << endl;
        }
    } while(choice != 3);

    return 0;
}