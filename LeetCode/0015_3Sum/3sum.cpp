class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // return bruteForce(nums);
        // return twoPointers1(nums);
        // return twoPointers1_improve(nums);
        return twoPointers2(nums);
    }

    // time complexity: O(n^3)
    vector<vector<int>> bruteForce(vector<int>& nums){
        vector<vector<int>> result;
        int n = nums.size();
        std::sort(nums.begin(), nums.end());  // to help on avoding duplicate triplets
        for(int i = 0; i < n; i++){
            if(i > 0 && nums[i] == nums[i-1])
                continue;  // skip identical number except the first one

            for(int j = i + 1; j < n; j++){
                if(j > i + 1 && nums[j] == nums[j-1])
                    continue;

                for(int k = j + 1; k < n; k++){
                    if(k > j + 1 && nums[k] == nums[k-1])
                        continue;

                    if(nums[i]+nums[j]+nums[k] == 0)
                        result.push_back({nums[i], nums[j], nums[k]});
                }
            }
        }
        return result;
    }

    // time complexity: O(n^2)
    vector<vector<int>> twoPointers1(vector<int>& nums){
        vector<vector<int>> result;
        int n = nums.size();
        std::sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++){
            int target = -nums[i];
            int left = i + 1, right = n - 1;
            while(left < right){
                int sum = nums[left] + nums[right];
                if(sum < target)
                    left++;

                else if(sum > target)
                    right--;

                else {
                    result.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    while(left < right && nums[left] == nums[left-1]) left++;
                    while(left < right && nums[right] == nums[right+1]) right--;
                }
            }
            while(i + 1 < n && nums[i] == nums[i+1]) i++;
        }
        return result;
    }

    // time complexity: O(n^2)
    vector<vector<int>> twoPointers1_improve(vector<int>& nums){
        vector<vector<int>> result;
        int n = nums.size();
        std::sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++){
            if(nums[i] > 0) break;  // since it's already sorted as a<b<c, if a>0, then b+c<0 is impossible

            int target = -nums[i];
            int left = i + 1, right = n - 1;
            while(left < right){
                int sum = nums[left] + nums[right];
                if(sum < target) left++;
                else if(sum > target) right--;
                else {
                    result.push_back({nums[i], nums[left], nums[right]});
                    while(left < right && nums[++left] == nums[left-1]);
                    while(left < right && nums[--right] == nums[right+1]);
                }   
            }
            while(i + 1 < n && nums[i] == nums[i+1]) i++;
        }
        return result;
    }

    // time complexity: O(n^2)
    vector<vector<int>> twoPointers2(vector<int>& nums){
        vector<vector<int>> result;
        int n = nums.size();
        std::sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++){
            if(nums[i] > 0) break;
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int target = -nums[i];
            for(int j = i + 1, k = n - 1; j < k;){
                int sum = nums[j] + nums[k];
                if(j > i + 1 && nums[j] == nums[j-1] || sum < target) j++;
                else if(k < n - 1 && nums[k] == nums[k+1] || sum > target) k--;
                else result.push_back({nums[i], nums[j++], nums[k--]});
            }
        }
        return result;
    }
};
