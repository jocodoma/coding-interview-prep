#include <iostream>

// pass by value
void swap_pass_by_value(int a, int b){
    int tmp = a;
    a = b;
    b = tmp;
}

// pass by reference
void swap_pass_by_reference(int& a, int& b){
    int tmp = a;
    a = b;
    b = tmp;
}

// pass a pointer by value
void swap_pass_pointer_by_value(int* a, int* b){
    int *tmp = a;
    a = b;
    b = tmp;
}

// pass a pointer by reference
void swap_pass_pointer_by_reference(int*& a, int*& b){
    int *tmp = a;
    a = b;
    b = tmp;
}

// pass double pointer by value
void swap_pass_double_pointer_by_value(int** a, int** b){
    int **tmp = a;
    a = b;
    b = tmp;
}

// pass double pointer by reference
void swap_pass_double_pointer_by_reference(int**& a, int**& b){
    int **tmp = a;
    a = b;
    b = tmp;
}

int main(){
    int a = 3, b = 5;
    int *ptr_a = &a;
    int *ptr_b = &b;
    int **pptr_a = &ptr_a, **pptr_b = &ptr_b;

    std::cout << "main() - before: \n";
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "ptr_a = " << ptr_a << ", ptr_b = " << ptr_b << std::endl;
    std::cout << "*ptr_a = " << *ptr_a << ", *ptr_b = " << *ptr_b << std::endl;
    std::cout << "pptr_a = " << pptr_a << ", pptr_b = " << pptr_b << std::endl;
    std::cout << "*pptr_a = " << *pptr_a << ", *pptr_b = " << *pptr_b << std::endl;

    std::cout << "\nmain() - after: \n";

    swap_pass_by_value(a, b);                               // output: No change
    std::cout << "swap_pass_by_value(): " << "a = " << a << ", b = " << b << std::endl;

    swap_pass_by_reference(a, b);                           // output: Swapped
    std::cout << "swap_pass_by_reference(): " << "a = " << a << ", b = " << b << std::endl;

    swap_pass_pointer_by_value(ptr_a, ptr_b);               // output: No change
    std::cout << "swap_pass_pointer_by_value(): " << "ptr_a = " << ptr_a << ", ptr_b = " << ptr_b << std::endl;
    std::cout << "swap_pass_pointer_by_value(): " << "*ptr_a = " << *ptr_a << ", *ptr_b = " << *ptr_b << std::endl;

    swap_pass_pointer_by_reference(ptr_a, ptr_b);           // output: Swapped
    std::cout << "swap_pass_pointer_by_reference(): " << "ptr_a = " << ptr_a << ", ptr_b = " << ptr_b << std::endl;
    std::cout << "swap_pass_pointer_by_reference(): " << "*ptr_a = " << *ptr_a << ", *ptr_b = " << *ptr_b << std::endl;

    swap_pass_double_pointer_by_value(pptr_a, pptr_b);      // output: No change
    std::cout << "swap_pass_double_pointer_by_value(): " << "pptr_a = " << pptr_a << ", pptr_b = " << pptr_b << std::endl;
    std::cout << "swap_pass_double_pointer_by_value(): " << "*pptr_a = " << *pptr_a << ", *pptr_b = " << *pptr_b << std::endl;

    swap_pass_double_pointer_by_reference(pptr_a, pptr_b);  // output: Swapped
    std::cout << "swap_pass_double_pointer_by_reference(): " << "pptr_a = " << pptr_a << ", pptr_b = " << pptr_b << std::endl;
    std::cout << "swap_pass_double_pointer_by_reference(): " << "*pptr_a = " << *pptr_a << ", *pptr_b = " << *pptr_b << std::endl;

    return 0;
}
