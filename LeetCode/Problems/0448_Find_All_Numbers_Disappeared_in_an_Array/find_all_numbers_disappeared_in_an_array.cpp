class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // return bruteForce(nums);
        // return hashMap(nums);
        return arrayIndex(nums);
    }

    // time complexity: O(n^2), space complexity: O(1)
    vector<int> bruteForce(vector<int>& nums){
        int length = nums.size();
        if(!length) return {};
        std::vector<int> output;
        for(int i = 1; i < length+1; i++){
            bool isFound = false;
            for(int j = 0; j < length; j++){
                if(nums[j] == i){
                    isFound = true;
                    break;
                }
            }
            if(!isFound) output.push_back(i);
        }
        return output;
    }

    // time complexity: O(n), space complexity: O(n)
    vector<int> hashMap(vector<int>& nums){
        int length = nums.size();
        if(!length) return {};
        std::vector<int> output;
        std::unordered_map<int, bool> map;

        for(int i = 0; i < length; i++)
            map[i+1] = false;
        
        for(int i = 0; i < length; i++)
            if(map.count(nums[i])) map[nums[i]] = true;

        for(const auto& it : map)
            if(!it.second) output.push_back(it.first);

        return output;
    }

    // time complexity: O(n), space complexity: O(1)
    vector<int> arrayIndex(vector<int>& nums){
        int length = nums.size();
        if(!length) return {};
        std::vector<int> output;

        for(int i = 0; i < length; i++){
            int idx = std::abs(nums[i]) - 1;  // index start from 0
            nums[idx] = nums[idx] > 0 ? -nums[idx] : nums[idx];  // set nums[idx] to negative to indicate the number "idx" is visited
        }

        for(int i = 0; i < length; i++)
            if(nums[i] > 0) output.push_back(i+1);

        return output;
    }
};
