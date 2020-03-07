#include <iostream>
#include <vector>

// Reference:
// https://en.cppreference.com/w/cpp/language/range-for

int main(){
    std::vector<int> v = {0, 1, 2, 3, 4, 5};

    // access by const reference
    for(const int& i : v)
        std::cout << i << ' ';
    std::cout << std::endl;
    
    // access by value
    // the type of i is int
    for(auto i : v)
        std::cout << i << ' ';
    std::cout << std::endl;

    // access by forwarding reference
    // the type of i is int&
    for(auto&& i : v)
        std::cout << i << ' ';
    std::cout << std::endl;

    // access by forwarding reference
    // the type of i is const int&
    const auto& cv = v;
    for(auto&& i : cv)
        std::cout << i << ' ';
    std::cout << std::endl;

    // the initializer may be a braced-init-list
    for(int n : {5, 4, 3, 2, 1, 0})
        std::cout << n << ' ';
    std::cout << std::endl;

    // the initializer may be an array
    int a[] = {4, 5, 6, 7, 8, 9};
    for(int n : a)
        std::cout << n << ' ';
    std::cout << std::endl;

    // the loop variable need not be used
    for([[maybe_unused]] int n : a)
        std::cout << "1" << ' ';
    std::cout << std::endl;  

    return 0;
}
