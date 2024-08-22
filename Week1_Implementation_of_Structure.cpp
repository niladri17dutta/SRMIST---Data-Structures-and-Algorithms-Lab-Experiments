#include <iostream>
#include <string>
using namespace std;

struct Person {
    string name;
    int age;
    string city;
};

void displayPerson(const Person& p) {
    cout << "Name: " << p.name << endl;
    cout << "Age: " << p.age << endl;
    cout << "City: " << p.city << endl;
}

int main() {
    Person person1;
    
    person1.name = "John Doe";
    person1.age = 30;
    person1.city = "New York";
    
    cout << "Person 1 Details:" << endl;
    displayPerson(person1);
    
    Person person2 = {"Jane Smith", 25, "Los Angeles"};
    
    cout << "\nPerson 2 Details:" << endl;
    displayPerson(person2);
    
    return 0;
}