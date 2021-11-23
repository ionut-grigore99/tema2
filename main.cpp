#include "src/Toy/src/Toy.hpp"
#include "src/Child/src/Child.hpp"

#include <iostream>
using namespace std;

int main()
{
    Toy toy("Barbie doll", "BarbieEnterprise", 120);
    Toy toy1("Bugs Bunny doll", "Disney", 90);
    Toy toy2("Race car", "Nerf", 55.9);

    Child child("Ion", "Popescu", 6);

    child.addToy(toy);
    child.addToy(toy1);
    child.addToy(toy2);

    child.printChild();

    DerivedToy dtoy("Bugs Bunny", "Noriel", 73.2, "bumbac");

    DerivedToy dtoy1(dtoy);
    DerivedToy dtoy2;
    dtoy2=dtoy;
    dtoy.printDerivedToy();
    dtoy1.printDerivedToy();
    dtoy2.printDerivedToy();

    ExampleItem12Last ex=ExampleItem12Last(3,4);
    ex.printExampleItem12Last();
    ExampleItem12Last ex1(ex);
    ex1.printExampleItem12Last();
    ExampleItem12Last ex2;
    ex2=ex;
    ex2.printExampleItem12Last();

/*
    //use copy constructor to copy a child
    Child child1(child);
    child1.printChild();

    //use copy constructor to create a toy
    Toy toy3(toy);
    toy3.printToy();

    //use copy assignment operator for child
    Child child2;
    child2 = child1;

    child2.printChild();

    //use copy assignment operator for toy
    Toy toy4;
    toy4 = toy1;

    //self-assign
    toy4 = toy4;

    toy4.printToy();
*/
    return 0;
}