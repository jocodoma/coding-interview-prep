#include <iostream>

using namespace std;

void const_data_ptr(){
    int value = 0;

    // data/value is constant, but pointer is not
    const int *p1_value = &value;
    cout << "value = " << value << ", p1_value = " << p1_value << "\n";

    p1_value++;
    cout << "value = " << value << ", p1_value = " << p1_value << "\n";

    // point is constant, but data/value is not
    int * const p2_value = &value;
    cout << "value = " << value << ", p2_value = " << p2_value << "\n";

    *p2_value = 77;
    cout << "value = " << value << ", p2_value = " << p2_value << "\n";

    // both data/value and pointer are constant
    const int * const p3_value = &value;
    cout << "value = " << value << ", p3_value = " << p3_value << "\n";
}

void change_const(){
    // cast away const
    const int i = 3;
    const_cast<int&>(i) = 6;
    cout << "i = " << i << "\n";

    // const
    int j = 6;
    static_cast<const int&>(j);
    j = 9;
    cout << "j = " << j << "\n";
}

class Dog{
public:
    Dog(){ cout << "= Dog constructor =\n"; }
    void setName(const string& dogName){ name = dogName; }
    const string& getName(){ return name; }
    void printName() const { cout << "dog name: " << name << "\n"; }

private:
    string name;
};

void const_with_functions(){
    Dog dog1;
    dog1.setName("pica");
    const string &dog1Name = dog1.getName();
    cout << "dog1 name: " << dog1Name << "\n";

    Dog dog2;
    dog2.setName("chew");
    dog2.printName();
}

int main(){
    const_data_ptr();

    change_const();

    const_with_functions();

    return 0;
}
