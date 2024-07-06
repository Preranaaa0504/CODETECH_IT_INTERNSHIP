#include <iostream>
#include <cstring> // For strcmp function
using namespace std;

class Student {
public:
    char name[50];
    int rollNumber;
    char grade;

    void setStudentInfo() {
        cout << "Enter student's name: ";
        cin.ignore(); // Ignore any leftover newline characters
        cin.getline(name, 50); // Read the name
        cout << "Enter roll number: ";
        cin >> rollNumber; // Read the roll number
        cout << "Enter grade: ";
        cin >> grade; // Read the grade
    }

    void displayInfo() {
        cout << "Name: " << name << ", Roll Number: " << rollNumber << ", Grade: " << grade << endl;
    }
};

class StudentManagementSystem {
private:
    Student students[100];
    int studentCount;

public:
    StudentManagementSystem() {
        studentCount = 0; // Initialize student count to zero
    }

    bool isRollNumberTaken(int rollNumber) {
        for (int i = 0; i < studentCount; i++) {
            if (students[i].rollNumber == rollNumber) {
                return true; // Roll number is already taken
            }
        }
        return false; // Roll number is not taken
    }

    void addStudent() {
        if (studentCount < 100) {
            Student newStudent;
            newStudent.setStudentInfo();
            
            // Check if roll number already exists
            if (isRollNumberTaken(newStudent.rollNumber)) {
                cout << "Roll number " << newStudent.rollNumber << " has already been allotted." << endl;
            } else {
                students[studentCount] = newStudent;
                studentCount++;
                cout << "Student added successfully." << endl;
            }
        } else {
            cout << "Maximum number of students reached (100)." << endl;
        }
    }

    void editStudent() {
        int rollNumber;
        cout << "Enter roll number of the student to edit: ";
        cin >> rollNumber;
        for (int i = 0; i < studentCount; i++) {
            if (students[i].rollNumber == rollNumber) {
                cout << "Editing student info: " << endl;
                // Temporarily store current roll number
                int currentRollNumber = students[i].rollNumber;
                
                students[i].setStudentInfo();
                
                // Check if the new roll number is already taken
                if (students[i].rollNumber != currentRollNumber && isRollNumberTaken(students[i].rollNumber)) {
                    cout << "Roll number " << students[i].rollNumber << " has already been allotted. Reverting changes." << endl;
                    students[i].rollNumber = currentRollNumber; // Revert to previous roll number
                } else {
                    cout << "Student information updated successfully." << endl;
                }
                return;
            }
        }
        cout << "Student not found." << endl;
    }

    void deleteStudent() {
        int rollNumber;
        cout << "Enter roll number of the student to delete: ";
        cin >> rollNumber;
        for (int i = 0; i < studentCount; i++) {
            if (students[i].rollNumber == rollNumber) {
                for (int j = i; j < studentCount - 1; j++) {
                    students[j] = students[j + 1];
                }
                studentCount--;
                cout << "Student deleted successfully." << endl;
                return;
            }
        }
        cout << "Student not found." << endl;
    }

    void displayStudent() {
        int rollNumber;
        cout << "Enter roll number of the student to display: ";
        cin >> rollNumber;
        for (int i = 0; i < studentCount; i++) {
            if (students[i].rollNumber == rollNumber) {
                students[i].displayInfo();
                return;
            }
        }
        cout << "Student not found." << endl;
    }

    void displayStudentData() {
        if (studentCount == 0) {
            cout << "No students added yet." << endl;
        } else {
            cout << "List of Students:" << endl;
            for (int i = 0; i < studentCount; i++) {
                students[i].displayInfo();
            }
        }
    }
};

int main() {
    StudentManagementSystem sms;
    int choice;
    while (true) {
        cout << "\n1. Add Student\n2. Edit Student\n3. Delete Student\n4. Display Student\n5. Display All Students\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                sms.addStudent();
                break;
            case 2:
                sms.editStudent();
                break;
            case 3:
                sms.deleteStudent();
                break;
            case 4:
                sms.displayStudent();
                break;
            case 5:
                sms.displayStudentData();
                break;
            case 6:
                return 0;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    }
    return 0;
}

