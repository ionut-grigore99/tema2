#include "Toy.hpp"


//In a constructor, prefer use of the member initialization list to as-
//signment inside the body of the constructor. List data members in
//the initialization list in the same order they’re declared in the class. (ITEM 4)
Toy::Toy() : name("None"), manufacturer("None"), price(0) {}

Toy::Toy(string name, string manufacturer, double price)  //constructor "clasic" doar cu assignment-uri
{
    this -> name = name;
    this -> manufacturer = manufacturer;
    this -> price = price;
}

 Toy::Toy(const Toy& toy)  // copy constructor
 {
     name = toy.name;
     manufacturer = toy.manufacturer;
     price = toy.price;
 }

Toy& Toy::operator=(const Toy& toy) // copy assignment operator
{  
    
    if(this == &toy) return *this;  // identity test: if a self-assignment,
                                    // do nothing (ITEM 11 !!!)


    this -> name = toy.name;
    this -> manufacturer = toy.manufacturer;
    this -> price = toy.price;

//Have assignment operators return a reference to *this!!!! (ITEM 10)
    return *this;
}

Toy::~Toy() { } //toy destructor

void Toy::printToy() 
{
    cout << name << " " << manufacturer << " " << price << " lei" << endl;

    cout << endl;
}

string Toy::getName() { return name; }

string Toy::getManufacturer() { return manufacturer; }

double Toy::getPrice() { return price; }

//////////////////////////// DerivedToy!!! ////////////////////////////

//Copying functions should be sure to copy all of an object’s data
//members and all of its base class parts!!! (ITEM 12)


DerivedToy::DerivedToy() : Toy (), material("none") {}


DerivedToy::DerivedToy(string name, string manufacturer, double price, string material)  //constructor "clasic" doar cu assignment-uri
:Toy(name, manufacturer, price)
{
    this -> material = material;
}

 DerivedToy::DerivedToy(const DerivedToy& dt)  // copy constructor
 : Toy(dt), // invoke base class copy ctor (ITEM 12!!!)
   material(dt.material)
   {}


DerivedToy& DerivedToy::operator=(const DerivedToy& dt) // copy assignment operator
{
 if(this == &dt) return *this;  // identity test: if a self-assignment,
                                    // do nothing (ITEM 11 !!!)

Toy::operator=(dt); // assign base class parts (ITEM 12!!!)
material = dt.material;

//Have assignment operators return a reference to *this!!!! (ITEM 10)
return *this;
}


DerivedToy::~DerivedToy() { } //DerivedToy destructor

void DerivedToy::printDerivedToy() 
{

  cout << name << " " << manufacturer << " " << price << " lei " << material << endl;

    cout << endl;
}

//////////////////////////////////////// ExampleItem12Last!!! ////////////////////////////

ExampleItem12Last::ExampleItem12Last() : firstParameter(0), secondParameter(0) {}


ExampleItem12Last::ExampleItem12Last(int firstParameter, int secondParameter)  //constructor "clasic" doar cu assignment-uri
{
    this -> firstParameter = firstParameter;
    this -> secondParameter = secondParameter;
}

void ExampleItem12Last::init(const ExampleItem12Last& ex) //ITEM 12!!!!!!!
{
    this -> firstParameter = ex.firstParameter;
    this -> secondParameter = ex.secondParameter;
}


 ExampleItem12Last::ExampleItem12Last(const ExampleItem12Last& ex)  // copy constructor
   {
       init(ex); //ITEM 12!!!!
   }


ExampleItem12Last& ExampleItem12Last::operator=(const ExampleItem12Last& ex) // copy assignment operator
{
 if(this == &ex) return *this;  // identity test: if a self-assignment,
                                    // do nothing (ITEM 11 !!!)

init(ex); //ITEM 12!!!!

//Have assignment operators return a reference to *this!!!! (ITEM 10)
return *this;
}


ExampleItem12Last::~ExampleItem12Last() { } //ExampleItem12Last destructor

void ExampleItem12Last::printExampleItem12Last() 
{

  cout << firstParameter << " " << secondParameter << endl;

    cout << endl;
}