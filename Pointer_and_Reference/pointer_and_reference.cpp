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
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// pass a pointer by reference
void swap_pass_pointer_by_reference(int*& a, int*& b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// pass double pointer by value
void swap_pass_double_pointer_by_value(int** a, int** b){
    int tmp = **a;
    **a = **b;
    **b = tmp;
}

// pass double pointer by reference
void swap_pass_double_pointer_by_reference(int**& a, int**& b){
    int tmp = **a;
    **a = **b;
    **b = tmp;
}

int main(){
    int a = 3, b = 5;
    int *ptr_a = &a, *ptr_b = &b;
    int **pptr_a = &ptr_a, **pptr_b = &ptr_b;

    std::cout << "main() - before: ";
    std::cout << "a = " << a << ", b = " << b << std::endl;

    swap_pass_by_value(a, b);                               // output: No change
    swap_pass_by_reference(a, b);                           // output: Changed
    swap_pass_pointer_by_value(&a, &b);                     // output: Changed
    swap_pass_pointer_by_reference(ptr_a, ptr_b);           // output: Changed
    swap_pass_double_pointer_by_value(&ptr_a, &ptr_b);      // output: Changed
    swap_pass_double_pointer_by_reference(pptr_a, pptr_b);  // output: Changed

    std::cout << "main() - after: ";
    std::cout << "a = " << a << ", b = " << b << std::endl;

    return 0;
}
