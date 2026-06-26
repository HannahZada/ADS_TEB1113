#include <iostream>
#include <string>
using namespace std;

struct Student {
    string id;
    string name;
    string course;
    int age;
};

int main()
{
    Student student[5];

    for (int i = 0; i < 5; i++) {
        cout << "\nStudent " << i + 1 << endl;

        cout << "ID: ";
        cin >> student[i].id;

        cin.ignore(); // important for getline

        cout << "Name: ";
        getline(cin, student[i].name);

        cout << "Course: ";
        getline(cin, student[i].course);

        cout << "Age: ";
        cin >> student[i].age;
    }

    cout << "\n=== ALL STUDENTS ===\n";
    for (int i = 0; i < 5; i++) {
        cout << "\nID: " << student[i].id << endl;
        cout << "Name: " << student[i].name << endl;
        cout << "Course: " << student[i].course << endl;
        cout << "Age: " << student[i].age << endl;
    }


    string searchID;
    cout << "\nEnter ID to search: ";
    cin >> searchID;

    bool found = false;

    for (int i = 0; i < 5; i++) {
        if (student[i].id == searchID) {
            cout << "\nStudent found:\n";
            cout << "ID: " << student[i].id << endl;
            cout << "Name: " << student[i].name << endl;
            cout << "Course: " << student[i].course << endl;
            cout << "Age: " << student[i].age << endl;

            found = true;

            int choice;
            cout << "\nUpdate this student? (1 = Yes, 0 = No): ";
            cin >> choice;

            if (choice == 1) {
                cin.ignore();

                cout << "New Name: ";
                getline(cin, student[i].name);

                cout << "New Course: ";
                getline(cin, student[i].course);

                cout << "New Age: ";
                cin >> student[i].age;

                cout << "\nUpdated successfully!\n";
            }

            break;
        }
    }

    if (!found) {
        cout << "\nStudent not found!\n";
    }

    return 0;
}
}
