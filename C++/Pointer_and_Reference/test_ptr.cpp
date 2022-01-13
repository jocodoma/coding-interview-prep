

#include <iostream>
using namespace std;

void set_77(int* p_value){
    *p_value = 77;
}

int set_number(void){
    int *p_value;
    set_77(p_value);
    return *p_value;
}

int main(void){
    cout << set_number() << "\n";
    return 0;
}



// #include <iostream>

// using namespace std;

// void set_77(int* p_value){
//     *p_value = 77;
// }

// int set_number(){
//     int value;
//     int *p_value = &value;
//     set_77(p_value);
//     return *p_value;
// }

// int main(){
//     cout << set_number() << "\n";
//     return 0;
// }



// #include <stdio.h>
// #include <string.h>

// #define VAR_SIZE 20

// int main(){
//     const unsigned char var[VAR_SIZE] = {0x20, 0x50, 0xF3};
//     unsigned char var2[VAR_SIZE];

//     memcpy(var2, var, sizeof(var));

//     if(var == var2)
//         printf("Arrays are the same\n");
//     else
//         printf("Arrays are not the same\n");

//     // for(int i = 0; i < VAR_SIZE; i++){
//     //     if(var[i] == var2[i])
//     //         printf("%d - same\n", i);
//     //     else
//     //         printf("%d - diff\n", i);
//     // }

//     // int ret = memcmp(var, var2, sizeof(var));
//     // printf("ret=%d\n", ret);

//     return 0;
// }


// #include <iostream>

// using namespace std;

// void swap_pass_int_by_reference(int& a, int& b){
//     int tmp = a;
//     a = b;
//     b = tmp;
// }

// void swap_pass_pointer_by_value(int* a, int* b){
//     int tmp = *a;
//     *a = *b;
//     *b = tmp;
// }

// int main(){
//     // case 1
//     int a = 3, b =5;
//     cout << "Case 1 - pass int by reference\n";
//     cout << "[b4] a = " << a << ", b = " << b << "\n";
//     swap_pass_int_by_reference(a, b);
//     cout << "[af] a = " << a << ", b = " << b << "\n";

//     // case 2
//     a = 3, b =5;
//     cout << "\nCase 2 - pass pointer by value\n";
//     cout << "[b4] a = " << a << ", b = " << b << "\n";
//     int *ptr_a = &a;
//     int *ptr_b = &b;
//     swap_pass_pointer_by_value(ptr_a, ptr_b);
//     cout << "[af] a = " << a << ", b = " << b << "\n";

//     return 0;
// }
