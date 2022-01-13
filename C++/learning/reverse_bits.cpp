#include <iostream>
#include <string>

// template <typename T>
// void myswap(T* a, T* b){
//     T tmp = *a;
//     *a = *b;
//     *b = tmp;
// }

template <typename T>
void myswap(T& a, T& b){
    T tmp = a;
    a = b;
    b = tmp;
}

void reverse_bits_str(std::string& n){
    std::reverse(n.begin(), n.end());
}

void reverse_bits_str2(std::string& n){
    int l = 0;
    int r = n.length() - 1;
    while(l < r){
        // std::swap(n[l], n[r]);
        myswap(n[l], n[r]);
        l++;
        r--;
    }
}

void reverse_bits_int(int& n){
    int l = 7;
    int r = 0;
    while(l > r){
        int l_bit = (n & 1 << l) >> l & 1;
        int r_bit = (n & 1 << r) >> r & 1;
        if(l_bit ^ r_bit){
            n = n ^ 1 << l;
            n = n ^ 1 << r;
        }
        l--;
        r++;
    }
}

void reverse_bits_int2(int& n){
    int ans = 0;
    for(int i = 0; i < 8; i++)
        ans = (ans << 1) | (n >> i & 1);
    n = ans;
}

int main(){
    // std::string n = "01100100";
    // std::cout << "n_ori: " << n << "\n";
    // reverse_bits_str(n);
    // reverse_bits_str2(n);
    // std::cout << "n_new: " << n << "\n";

    int n = 100;
    std::cout << "n_ori: " << n << ", " << std::bitset<8>(n) << "\n";
    // reverse_bits_int(n);
    reverse_bits_int2(n);
    std::cout << "n_new: " << n << ", " << std::bitset<8>(n) << "\n";

    return 0;
}
