#ifndef TOY_H
#define TOY_H

#include <iostream>
#include <string>

using namespace std;

class Toy 
{
    protected:
        string name;
        string manufacturer;
        double price;

    public:
        Toy();
        Toy(string name, string manufacturer, double price);
        Toy(const Toy& toy);
        Toy& operator=(const Toy& toy);
        ~Toy();
        
        void printToy();
        string getName();
        string getManufacturer();
        double getPrice();
};

class DerivedToy: public Toy { // a derived class

    private:
        string material;

    public:
        DerivedToy();
        DerivedToy(string name, string manufacturer, double price, string material);
        DerivedToy(const DerivedToy& dt);
        DerivedToy& operator=(const DerivedToy& dt);
        ~DerivedToy();

        void printDerivedToy();

};


class ExampleItem12Last { //class used for last part of ITEM 12!!
//Don’t try to implement one of the copying functions in terms of the
//other. Instead, put common functionality in a third function that
//both call.

    private:
        int firstParameter;
        int secondParameter;

    public:
        ExampleItem12Last(int firstParameter,int secondParameter);
        void init(const ExampleItem12Last& ex); //ITEM 12!!!!
        ExampleItem12Last();
        ExampleItem12Last(const ExampleItem12Last& ex);
        ExampleItem12Last& operator=(const ExampleItem12Last& ex);
        ~ExampleItem12Last();

        void printExampleItem12Last();

};

#endif