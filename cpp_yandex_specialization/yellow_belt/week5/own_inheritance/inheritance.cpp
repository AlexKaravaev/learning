#include <iostream>

using namespace std;

class Animal {
public:
    // ваш код
    
    Animal(const string& iName): Name(iName){}
    const string Name;

    // Animal& operator=(Animal other)
    // {
    //     return new*(this) Animal(other.Name);
    // }
};


class Dog: public Animal {
public:
    // ваш код
    Dog(const string& iName): Animal(iName){}


    void Bark() {
        cout << Name << " barks: woof!" << endl;
    }
};


int main(){
    Dog doggy("baby");
    // Animal base;
    // base = static_cast<Animal>(doggy);
    // std::cout << "Base name " << base.Name << std::endl;
    doggy.Bark();

}