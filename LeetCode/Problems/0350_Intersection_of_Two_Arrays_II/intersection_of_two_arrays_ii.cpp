#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution{
public:
    Solution(){}
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2){
        // return hashTable(nums1, nums2);
        return sortedTwoPointers(nums1, nums2);
    }

private:
    // time complexity: O(m+n)
    // space complexity: O(min(m,n)), choose the smaller one if possible
    vector<int> hashTable(vector<int>& nums1, vector<int>& nums2){
        if(nums1.size() > nums2.size())
            return hashTable(nums2, nums1);

        unordered_map<int, int> map;
        vector<int> res;

        // build the map with the smaller size of input array
        for(int n : nums1)
            map[n]++;

        for(int n : nums2)
            if(map.count(n) && map[n] > 0){
                map[n]--;
                res.push_back(n);
            }

        return res;
    }

    // time complexity: O(max(mlogm, nlogn)), due to sorting algorithm
    // time complexity: O(min(m,n)), if inputs are already sorted
    // space complexity: O(1)
    vector<int> sortedTwoPointers(vector<int>& nums1, vector<int>& nums2){
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> res;
        unsigned int p1 = 0, p2 = 0;

        while(p1 < nums1.size() && p2 < nums2.size()){
            if(nums1[p1] == nums2[p2]){
                res.push_back(nums1[p1]);
                p1++;
                p2++;
            }
            else if(nums1[p1] > nums2[p2]){
                p2++;
            }
            else{
                p1++;
            }
        }

        return res;
    }
};

string printVector(const vector<int>& nums){
    if(nums.empty())
        return "Empty Vector";

    string str;
    str.append("[");
    for(auto it = nums.begin(); it != nums.end(); ++it){
        if(it != nums.begin())
            str.append(", ");
        str.append(std::to_string(*it));
    }
    str.append("]");

    return str;
}

int main(){
    vector<int> nums1({1,2,2,1});
    vector<int> nums2({2,2});

    cout << "Input: nums1 = " << printVector(nums1) << ", nums2 = " << printVector(nums2) << "\n";

    Solution sol;
    vector<int> output;
    output = sol.intersect(nums1, nums2);
    cout << "Output: "<< printVector(output) << "\n\n";

    nums1 = {4,9,5};
    nums2 = {9,4,9,8,4};
    cout << "Input: nums1 = " << printVector(nums1) << ", nums2 = " << printVector(nums2) << "\n";

    output = sol.intersect(nums1, nums2);
    cout << "Output: "<< printVector(output) << "\n";

    return 0;
}
