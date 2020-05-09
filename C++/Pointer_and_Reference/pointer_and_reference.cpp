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
void swap_pass_pointer_by_value_1(int* a, int* b){
    int *tmp = a;
    a = b;
    b = tmp;
}

// pass a pointer by value
// swapped the values of pointers (a and b)
// note that tmp is int, not pointer point to int
// doing operations after dereference (*a, *b)
void swap_pass_pointer_by_value_2(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// pass a pointer by reference
void swap_pass_pointer_by_reference(int*& a, int*& b){
    int *tmp = a;
    a = b;
    b = tmp;
}

// pass double pointer by value
void swap_pass_double_pointer_by_value_1(int** a, int** b){
    int **tmp = a;
    a = b;
    b = tmp;
}

// pass double pointer by value
// note that tmp is a pointer point to int, not a double pointer
void swap_pass_double_pointer_by_value_2(int** a, int** b){
    int *tmp = *a;
    *a = *b;
    *b = tmp;
}

// pass double pointer by value
// note that tmp is int
void swap_pass_double_pointer_by_value_3(int** a, int** b){
    int tmp = **a;
    **a = **b;
    **b = tmp;
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

    swap_pass_by_value(a, b);                               // output: No change for the values of a and b
    std::cout << "swap_pass_by_value(): " << "a = " << a << ", b = " << b << std::endl;

    swap_pass_by_reference(a, b);                           // output: Swapped the values of a and b
    std::cout << "swap_pass_by_reference(): " << "a = " << a << ", b = " << b << std::endl;

    swap_pass_pointer_by_value_1(ptr_a, ptr_b);             // output: No change for both values and pointers
    std::cout << "swap_pass_pointer_by_value_1(): " << "ptr_a = " << ptr_a << ", ptr_b = " << ptr_b << std::endl;
    std::cout << "swap_pass_pointer_by_value_1(): " << "*ptr_a = " << *ptr_a << ", *ptr_b = " << *ptr_b << std::endl;
    std::cout << "swap_pass_pointer_by_value_1(): " << "a = " << a << ", b = " << b << std::endl;

    swap_pass_pointer_by_value_2(ptr_a, ptr_b);             // output: No change for pointers, but swapped the values of pointers. Swapped a and b.
    std::cout << "swap_pass_pointer_by_value_2(): " << "ptr_a = " << ptr_a << ", ptr_b = " << ptr_b << std::endl;
    std::cout << "swap_pass_pointer_by_value_2(): " << "*ptr_a = " << *ptr_a << ", *ptr_b = " << *ptr_b << std::endl;
    std::cout << "swap_pass_pointer_by_value_2(): " << "a = " << a << ", b = " << b << std::endl;

    swap_pass_pointer_by_reference(ptr_a, ptr_b);           // output: Swapped pointers, but no change for the value of a and b.
    std::cout << "swap_pass_pointer_by_reference(): " << "ptr_a = " << ptr_a << ", ptr_b = " << ptr_b << std::endl;
    std::cout << "swap_pass_pointer_by_reference(): " << "*ptr_a = " << *ptr_a << ", *ptr_b = " << *ptr_b << std::endl;
    std::cout << "swap_pass_pointer_by_reference(): " << "a = " << a << ", b = " << b << std::endl;

    swap_pass_double_pointer_by_value_1(pptr_a, pptr_b);    // output: No change for all
    std::cout << "swap_pass_double_pointer_by_value_1(): " << "pptr_a = " << pptr_a << ", pptr_b = " << pptr_b << std::endl;
    std::cout << "swap_pass_double_pointer_by_value_1(): " << "*pptr_a = " << *pptr_a << ", *pptr_b = " << *pptr_b << std::endl;
    std::cout << "swap_pass_double_pointer_by_value_1(): " << "**pptr_a = " << **pptr_a << ", **pptr_b = " << **pptr_b << std::endl;
    std::cout << "swap_pass_double_pointer_by_value_1(): " << "a = " << a << ", b = " << b << std::endl;

    swap_pass_double_pointer_by_value_2(pptr_a, pptr_b);    // output: No change for double pointers, but swapped pointers. No change for a and b.
    std::cout << "swap_pass_double_pointer_by_value_2(): " << "pptr_a = " << pptr_a << ", pptr_b = " << pptr_b << std::endl;
    std::cout << "swap_pass_double_pointer_by_value_2(): " << "*pptr_a = " << *pptr_a << ", *pptr_b = " << *pptr_b << std::endl;
    std::cout << "swap_pass_double_pointer_by_value_2(): " << "**pptr_a = " << **pptr_a << ", **pptr_b = " << **pptr_b << std::endl;
    std::cout << "swap_pass_double_pointer_by_value_2(): " << "a = " << a << ", b = " << b << std::endl;

    swap_pass_double_pointer_by_value_3(pptr_a, pptr_b);    // output: No change for double pointers and pointers, but swapped the value of a and b.
    std::cout << "swap_pass_double_pointer_by_value_3(): " << "pptr_a = " << pptr_a << ", pptr_b = " << pptr_b << std::endl;
    std::cout << "swap_pass_double_pointer_by_value_3(): " << "*pptr_a = " << *pptr_a << ", *pptr_b = " << *pptr_b << std::endl;
    std::cout << "swap_pass_double_pointer_by_value_3(): " << "**pptr_a = " << **pptr_a << ", **pptr_b = " << **pptr_b << std::endl;
    std::cout << "swap_pass_double_pointer_by_value_3(): " << "a = " << a << ", b = " << b << std::endl;

    swap_pass_double_pointer_by_reference(pptr_a, pptr_b);  // output: Swapped double pointers and pointers, but no change for the value of a and b.
    std::cout << "swap_pass_double_pointer_by_reference(): " << "pptr_a = " << pptr_a << ", pptr_b = " << pptr_b << std::endl;
    std::cout << "swap_pass_double_pointer_by_reference(): " << "*pptr_a = " << *pptr_a << ", *pptr_b = " << *pptr_b << std::endl;
    std::cout << "swap_pass_double_pointer_by_reference(): " << "**pptr_a = " << **pptr_a << ", **pptr_b = " << **pptr_b << std::endl;
    std::cout << "swap_pass_double_pointer_by_reference(): " << "a = " << a << ", b = " << b << std::endl;

    return 0;
}
