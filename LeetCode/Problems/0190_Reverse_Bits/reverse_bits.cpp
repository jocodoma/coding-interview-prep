#include <iostream>
#include <string>

class Solution{
public:
    std::string reverseBits(std::string n){
        // return reverse_str(n);
        return reverse_str_twoPointers(n);
    }

    uint32_t reverseBits(uint32_t n){
        // return onePass(n);
        return twoPointers(n);
    }

private:
    std::string reverse_str(std::string n){
        std::reverse(n.begin(), n.end());
        return n;
    }

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

    // void myswap(char& a, char& b){
    //     char tmp = a;
    //     a = b;
    //     b = tmp;
    // }

    std::string reverse_str_twoPointers(std::string n){
        int l = 0, r = 7;
        while(l < r){
            // std::swap(n[l], n[r]);
            myswap(n[l], n[r]);
            l++;
            r--;
        }
        return n;
    }

    // time complexity: O(n), space complexity: O(1)
    uint32_t onePass(uint32_t n){
        uint32_t ans = 0;
        for(int i = 0; i < 32; i++){
            uint32_t bit = n >> i & 1;
            ans = ans << 1;
            ans = ans | bit;

            // the above lines are same as follow
            // ans = (ans << 1) | (n >> i & 1);
        }

        return ans;
    }

    void swapBits(uint32_t& n, int l, int r){
        // do swap if XOR is true, otherwise return n
        // swap binary bit -> bit flipping (XOR)
        uint32_t bitL = n >> l & 1;
        uint32_t bitR = n >> r & 1;
        if(bitL ^ bitR){
            n = n ^ 1 << l;
            n = n ^ 1 << r;
        }
    }

    uint32_t twoPointers(uint32_t n){
        int l = 31, r = 0;
        while(l > r){
            swapBits(n, l, r);
            l--;
            r++;
        }

        return n;
    }
};


int main(){
    std::string n_str, ans_str;

    n_str = "00100110";
    ans_str = Solution().reverseBits(n_str);
    std::cout << "Input:  " << n_str << "\n";
    std::cout << "Output: " << ans_str << "\n\n";

    n_str = "11010110";
    ans_str = Solution().reverseBits(n_str);
    std::cout << "Input:  " << n_str << "\n";
    std::cout << "Output: " << ans_str << "\n\n";


    uint32_t n, ans;

    n = 43261596;
    ans = Solution().reverseBits(n);
    std::cout << "Input:  " << n << ", " << std::bitset<32>(n) << "\n";
    std::cout << "Output: " << ans << ", " << std::bitset<32>(ans) << "\n\n";

    n = 4294967293;
    ans = Solution().reverseBits(n);
    std::cout << "Input:  " << n << ", " << std::bitset<32>(n) << "\n";
    std::cout << "Output: " << ans << ", " << std::bitset<32>(ans) << "\n\n";

    return 0;
}
