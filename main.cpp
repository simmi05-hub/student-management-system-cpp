#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

struct Student {
    int roll;
    char name[50];
    float marks;
};

int main() {
    int choice;
    Student s;

    do {
        cout << "\n====== Student Management System ======";
        cout << "\n1. Add Student";
        cout << "\n2. View Students";
        cout << "\n3. Search Student";
        cout << "\n4. Delete Student";
        cout << "\n5. Update Student";
        cout << "\n6. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch(choice) {

            case 1: {
                ofstream file("students.txt", ios::app);

                cout << "Enter Roll: ";
                cin >> s.roll;

                cout << "Enter Name: ";
                cin >> s.name;

                cout << "Enter Marks: ";
                cin >> s.marks;

                file << s.roll << " " << s.name << " " << s.marks << endl;
                file.close();

                cout << "Student added successfully!\n";
                break;
            }

            case 2: {
                ifstream file("students.txt");

                cout << "\n--- Student Records ---\n";

                while(file >> s.roll >> s.name >> s.marks) {
                    cout << "\nRoll: " << s.roll;
                    cout << "\nName: " << s.name;
                    cout << "\nMarks: " << s.marks << endl;
                }

                file.close();
                break;
            }

            case 3: {
                int searchRoll;
                bool found = false;

                cout << "Enter Roll to search: ";
                cin >> searchRoll;

                ifstream file("students.txt");

                while(file >> s.roll >> s.name >> s.marks) {
                    if(s.roll == searchRoll) {
                        cout << "\nStudent Found!";
                        cout << "\nRoll: " << s.roll;
                        cout << "\nName: " << s.name;
                        cout << "\nMarks: " << s.marks << endl;
                        found = true;
                        break;
                    }
                }

                if(!found) {
                    cout << "Student not found\n";
                }

                file.close();
                break;
            }

            case 4: {
                int delRoll;
                bool found = false;

                cout << "Enter Roll to delete: ";
                cin >> delRoll;

                ifstream file("students.txt");
                ofstream temp("temp.txt");

                while(file >> s.roll >> s.name >> s.marks) {
                    if(s.roll == delRoll) {
                        found = true;
                        continue;
                    }
                    temp << s.roll << " " << s.name << " " << s.marks << endl;
                }

                file.close();
                temp.close();

                remove("students.txt");
                rename("temp.txt", "students.txt");

                if(found) {
                    cout << "Student deleted successfully!\n";
                } else {
                    cout << "Student not found\n";
                }

                break;
            }

            case 5: {
                int updateRoll;
                bool found = false;

                cout << "Enter Roll to update: ";
                cin >> updateRoll;

                ifstream file("students.txt");
                ofstream temp("temp.txt");

                while(file >> s.roll >> s.name >> s.marks) {
                    if(s.roll == updateRoll) {
                        found = true;

                        cout << "Enter new name: ";
                        cin >> s.name;

                        cout << "Enter new marks: ";
                        cin >> s.marks;
                    }

                    temp << s.roll << " " << s.name << " " << s.marks << endl;
                }

                file.close();
                temp.close();

                remove("students.txt");
                rename("temp.txt", "students.txt");

                if(found) {
                    cout << "Student updated successfully!\n";
                } else {
                    cout << "Student not found\n";
                }

                break;
            }

            case 6:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while(choice != 6);

    return 0;
}
