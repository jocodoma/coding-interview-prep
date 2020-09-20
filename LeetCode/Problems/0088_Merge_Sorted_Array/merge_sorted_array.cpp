class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        return solution(nums1, m, nums2, n);
    }

    // time complexity: O(n+m)
    // space complexity: O(1)
    void solution(vector<int>& nums1, int m, vector<int>& nums2, int n){
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while(j >= 0)
            nums1[k--] = (i >= 0 && nums1[i] > nums2[j]) ? nums1[i--] : nums2[j--];
    }
};
