#include "Child.hpp"

//In a constructor, prefer use of the member initialization list to as-
//signment inside the body of the constructor. List data members in
//the initialization list in the same order they’re declared in the class. (ITEM 4)
Child::Child() : firstName("None"), lastName("None"), age(0), toys({}) {};

Child::Child(string firstName, string lastName, int age) //constructor "clasic" doar cu assignment-uri
{
    this -> firstName = firstName;
    this -> lastName = lastName;
    this -> age = age;
}

Child::Child(const Child& child)  // copy constructor
{
    this -> firstName = child.firstName;
    this -> lastName = child.lastName;
    this -> age = child.age;
    this -> toys = child.toys;
}

Child& Child::operator=(const Child& child) // copy assignment operator
{
    
    if(this == &child) return *this;  // identity test: if a self-assignment,
                                      // do nothing (ITEM 11 !!!)

    this -> firstName = child.firstName;
    this -> lastName = child.lastName;
    this -> age = child.age;
    this -> toys = child.toys;

//Have assignment operators return a reference to *this!!!! (ITEM 10)
    return *this;
}

Child::~Child() //child destructor
{
    toys.clear();
}

void Child::addToy(Toy& toy)
{
    toys.push_back(toy);
}

void Child::printChild()
{
    cout << firstName << " " << lastName << " who is " << age << " years old has" << ":" << endl;
    
    for(Toy t : toys) {
        cout << "  • " << t.getName() << " from " << t.getManufacturer() << " costs " << t.getPrice() << " lei" << endl;
    }

    cout << endl;
}