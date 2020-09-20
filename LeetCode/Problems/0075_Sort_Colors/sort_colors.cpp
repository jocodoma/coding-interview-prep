class Solution {
public:
    void sortColors(vector<int>& nums) {
        // twoPassCountingSort(nums);
        // onePassCountingSort(nums);
        threePointers(nums);
    }

    // time complexity: O(2n) = O(n), space complexity: O(1)
    void twoPassCountingSort(vector<int>& nums){
        if(nums.empty()) return;
        int countRed = 0, countWhite = 0, countBlue = 0;
        int len = nums.size();
        for(int i = 0; i < len; i++){
            if(nums[i] == 0) countRed++;
            else if(nums[i] == 1) countWhite++;
            else if(nums[i] == 2) countBlue++;
        }
        for(int i = 0; i < len; i++){
            if(countRed-- > 0)nums[i] = 0;
            else if(countWhite-- > 0) nums[i] = 1;
            else if(countBlue-- > 0) nums[i] = 2;
        }
    }

    // time complexity: O(n), space complexity: O(1)
    void onePassCountingSort(vector<int>& nums){
        if(nums.empty()) return;
        int n0 = -1, n1 = -1, n2 = -1;
        int len = nums.size();
        for(int i = 0; i < len; i++){
            if(nums[i] == 0){
                nums[++n2] = 2;
                nums[++n1] = 1;
                nums[++n0] = 0;
            }
            else if(nums[i] == 1){
                nums[++n2] = 2;
                nums[++n1] = 1;
            }
            else if(nums[i] == 2){
                nums[++n2] = 2;
            }
        }
    }

    // time complexity: O(n), space complexity: O(1)
    void threePointers(vector<int>& nums){
        if(nums.empty()) return;
        int len = nums.size();
        int i = 0, left = 0, right = len - 1;
        while(i <= right){
            if(nums[i] == 0) std::swap(nums[i++], nums[left++]);
            else if(nums[i] == 1) i++;
            else if(nums[i] == 2) std::swap(nums[i], nums[right--]);
        }
    }
};
