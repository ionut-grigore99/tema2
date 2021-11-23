#ifndef CHILD_H
#define CHILD_H

#include "../../Toy/src/Toy.hpp"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Child
{
    private:
        string firstName;
        string lastName;
        int age;
        vector<Toy> toys;

    public:
        Child();
        Child(string firstName, string lastName, int age);
        Child(const Child& child);
        Child& operator=(const Child& child);
        ~Child();
        
        void addToy(Toy& toy);
        void printChild();
};

#endif