#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // return bruteForce(nums);
        // return sorting(nums);
        return hashset(nums);
    }

private:
    // time complexity: O(n**2), space complexity: O(1)
    bool bruteForce(vector<int>& nums){
        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                if(nums[i] == nums[j])
                    return true;
            }
        }

        return false;
    }

    // time complexity: O(nlogn) due to sorting
    // space complexity: O(1) without considering the space taken by sorting
    bool sorting(vector<int>& nums){
        std::sort(nums.begin(), nums.end());
        for(int i = 1; i < nums.size(); i++)
            if(nums[i-1] == nums[i])
                return true;

        return false;
    }

    // time complexity: O(n), spcae complexity: O(n)
    bool hashset(vector<int>& nums){
        unordered_set<int> set;
        for(int i = 0; i < nums.size(); i++){
            if(set.count(nums[i]))
                return true;
            else
                set.insert(nums[i]);
        }

        return false;
    }
};

// nums is passed by constant reference and cannot be changed by this function
string printVector(const vector<int>& nums, int len){
    string str;

    str.append("[");
    for(int i = 0; i < len; i++){
        if(i != 0)
            str.append(", ");
        str.append(std::to_string(nums[i]));
    }
    str.append("]");

    return str;
}

int main(){
    Solution sol;
    std::cout.setf(std::ios::boolalpha);

    vector<int> nums1({1,2,3,1});
    cout << "Input:  " << printVector(nums1, nums1.size()) << "\n";
    cout << "Output: " << sol.containsDuplicate(nums1) << "\n";

    vector<int> nums2({1,2,3,4});
    cout << "Input:  " << printVector(nums2, nums2.size()) << "\n";
    cout << "Output: " << sol.containsDuplicate(nums2) << "\n";

    vector<int> nums3({1,1,1,3,3,4,3,2,4,2});
    cout << "Input:  " << printVector(nums3, nums3.size()) << "\n";
    cout << "Output: " << sol.containsDuplicate(nums3) << "\n";

    return 0;
}
