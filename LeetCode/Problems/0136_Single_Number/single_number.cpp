class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // return hashMap(nums);
        return xorOP(nums);
    }

    // space complexity: O(n) - hash map
    int hashMap(vector<int>& nums){
        // build a map
        std::unordered_map<int, bool> map;
        for(int i = 0; i < nums.size(); i++)
            map.count(nums[i]) ? map[nums[i]] = true : map[nums[i]] = false;

        // traverse a map
        for(const auto& it : map)
            if(!it.second) return it.first;

        return -1;  // no single number found
    }

    // space complexity: O(1) - XOR
    int xorOP(vector<int>& nums){
        int singleNum = 0;
        for(int i = 0; i < nums.size(); i++)
            singleNum ^= nums[i];

        return singleNum;
    }
};
