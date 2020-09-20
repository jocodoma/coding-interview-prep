class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        // return hashTable(nums1, nums2);
        return sortedTwoPointers(nums1, nums2);
    }

private:
    // time complexity: O(m+n)
    // space complexity: O(min(m,n)), choose the smaller one if possible
    vector<int> hashTable(vector<int>& nums1, vector<int>& nums2){
        if(nums1.size() > nums2.size())
            hashTable(nums2, nums1);

        unordered_map<int, int> map;
        vector<int> res;

        // build the map with smaller size of input array
        for(int num : nums1)
            map[num]++;

        for(int num : nums2)
            if(map.count(num) && --map[num] >= 0)
                res.push_back(num);
        
        return res;
    }

    // time complexity: O(max(mlogm, nlogn)), due to sorting algorithm
    // space complexity: O(1)
    vector<int> sortedTwoPointers(vector<int>& nums1, vector<int>& nums2){
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> res;
        int p1 = 0, p2 = 0;

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
