#include<fstream> 
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

void findTopper(){
    if(students.empty()){
        cout << "No students yet!" << endl;
        return;
    }
    Student topper = students[0];
    for(auto s : students){
        if(s.marks > topper.marks) topper = s;
    }
    cout << "\n🏆 Topper: " << topper.name
         << " | Marks: " << topper.marks << endl;
}

void searchStudent(){
    string name;
    cout << "Enter name to search: ";
    cin >> name;

    bool found = false;
    for(auto s : students){
        if(s.name == name){
            cout << "Found! Roll: " << s.rollNo
                 << " | Marks: " << s.marks << endl;
            found = true;
            break;
        }
    }
    if(!found) cout << "Student not found!" << endl;
}

void sortByMarks(){
    if(students.empty()){
        cout << "No students yet!" << endl;
        return;
    }
    // Bubble sort on vector
    int n = students.size();
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){
            if(students[j].marks > students[j+1].marks){
                swap(students[j], students[j+1]);
            }
        }
    }
    cout << "Sorted by marks!" << endl;
    displayAll();
}

void calculateAverage(){
    if(students.empty()){
        cout << "No students yet!" << endl;
        return;
    }
    float sum = 0;
    for(auto s : students){
        sum += s.marks;
    }
    float avg = sum / students.size();
    cout << "Class Average: " << avg << endl;

    // Also show grade distribution
    int aCount=0, bCount=0, cCount=0, dCount=0;
    for(auto s : students){
        if(s.marks >= 90) aCount++;
        else if(s.marks >= 75) bCount++;
        else if(s.marks >= 60) cCount++;
        else dCount++;
    }
    cout << "Grade A: " << aCount << " students" << endl;
    cout << "Grade B: " << bCount << " students" << endl;
    cout << "Grade C: " << cCount << " students" << endl;
    cout << "Grade D: " << dCount << " students" << endl;
}

void saveToFile(){
    ofstream file("students.txt");
    if(!file){
        cout << "Error opening file!" << endl;
        return;
    }
    for(auto s : students){
        file << s.name << " "
             << s.rollNo << " "
             << s.marks << "\n";
    }
    file.close();
    cout << "Data saved to students.txt!" << endl;
}

void loadFromFile(){
    ifstream file("students.txt");
    if(!file) return;  // no file yet, skip silently

    students.clear();
    Student s;
    while(file >> s.name >> s.rollNo >> s.marks){
        students.push_back(s);
    }
    file.close();
    cout << "Data loaded!" << endl;
}

int main(){
    int choice;
    loadFromFile();
    do {
        cout << "\n=== Student Record System ===" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Display All" << endl;
        cout << "3. Find Topper" << endl;
        cout << "4. Search Student" << endl;
        cout << "5. sortByMarks" << endl;
        cout << "6. calculateAverage" << endl;
        cout << "7. saveToFile()" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice){
            case 1: addStudent(); break;
            case 2: displayAll(); break;
            case 3: findTopper(); break;
            case 4: searchStudent(); break;
            case 5: sortByMarks(); break;
            case 6: calculateAverage(); break;
            case 7: saveToFile(); break;
            case 8: cout << "Goodbye!" << endl; break;
            default: cout << "Invalid choice!" << endl;
        }
    } while(choice != 8);

    return 0;
}