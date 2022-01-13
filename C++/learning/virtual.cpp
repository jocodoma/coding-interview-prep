#include <iostream>

using namespace std;

class Dog{
public:
    // ~Dog(){ cout << "Dog destructor\n"; }
    virtual ~Dog(){ cout << "Dog destructor\n"; }
    // virtual void bark(){ cout << "Dog - bark\n"; }
};

class YellowDog : public Dog{
public:
    ~YellowDog(){ cout << "YellowDog destructor\n"; }
    void bark(){ cout << "YellowDog - bark\n"; }
};

class DogFactory{
public:
    static Dog* createYellowDog(){ return (new YellowDog); }
    // static shared_ptr<Dog> createYellowDog(){ return shared_ptr<Dog>(new YellowDog); }
    // create other dogs ..
};

int main(){
    Dog *dog = DogFactory::createYellowDog();
    // shared_ptr<Dog> dog = DogFactory::createYellowDog();

    delete dog;

    return 0;
}
