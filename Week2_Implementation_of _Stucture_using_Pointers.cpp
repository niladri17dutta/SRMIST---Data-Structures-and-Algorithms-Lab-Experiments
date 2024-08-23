#include <iostream>
#include <string>

using namespace std;

struct Person {
    string name;
    int age;
    string city;
};

void displayPerson(const Person* p) {
    cout << "Name: " << p->name << endl;
    cout << "Age: " << p->age << endl;
    cout << "City: " << p->city << endl;
}

int main() {
    Person* person1 = new Person;
    Person* person2 = new Person;

    cout << "Enter details for Person 1:" << endl;
    cout << "Name: ";
    getline(cin, person1->name);
    cout << "Age: ";
    cin >> person1->age;
    cin.ignore();
    cout << "City: ";
    getline(cin, person1->city);
    
    cout << "\nPerson 1 Details:" << endl;
    displayPerson(person1);

    cout << "\nEnter details for Person 2:" << endl;
    cout << "Name: ";
    getline(cin, person2->name);
    cout << "Age: ";
    cin >> person2->age;
    cin.ignore();
    cout << "City: ";
    getline(cin, person2->city);
    
    cout << "\nPerson 2 Details:" << endl;
    displayPerson(person2);
    
    delete person1;
    delete person2;
    
    return 0;
}