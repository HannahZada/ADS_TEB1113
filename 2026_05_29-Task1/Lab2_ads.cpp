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
		cout << "id: ";
		cin >> student[i].id;
		cout << "name: ";
		cin >> student[i].name;
		cout << "course: ";
		cin >> student[i].course;
		cout << "age: ";
		cin >> student[i].age;
	}
	for (int i = 0; i < 5; i++) {
		cout<< "id: " << student[i].id << endl;
		cout << "name: " << student[i].name << endl;
		cout << "course: " << student[i].course << endl;
		cout << "age: " << student[i].age << endl;
	}
	return 0;
}