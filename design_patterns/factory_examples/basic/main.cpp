#include <iostream>
#include <list>
#include "Factory.hpp"

using namespace std;


int main() {
    // Suppose class names are read from command line or some other user input
    list<string> names = {"Derived1", "Derived2"};
//    names.push_back("NoSuchName");
    
    // Instantiate required objects
    list<shared_ptr<Base>> objects;
    try {
        for (const string &name : names) {
            objects.push_back(Factory().create(name));
        }
    } catch (FactoryException& e) {
        cerr << "Error instantiating objects: " << e.what() << endl;
        exit(EXIT_FAILURE);
    }
    
    // Use them
    for (shared_ptr<Base> ptr : objects) {
        ptr->foo();
    }
    
    return 0;
}
