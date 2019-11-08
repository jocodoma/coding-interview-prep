class Solution {
public:
    int maxArea(vector<int>& height) {
        // return bruteForce(height);
        return twoPointers(height);
    }

    // time complexity: O(n^2), space complexity: O(1)
    int bruteForce(vector<int>& height){
        if(height.size() < 2) return 0;

        int n = height.size();
        int maxAreaVal = 0;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int h = std::min(height[i], height[j]);
                int w = j - i;
                maxAreaVal = std::max(maxAreaVal, w * h);
            }
        }
        return maxAreaVal;
    }

    // time complexity: O(n), space complexity: O(1)
    int twoPointers(vector<int>& height){
        if(height.size() < 2) return 0;

        int n = height.size();
        int maxAreaVal = 0, leftPtr = 0, rightPtr = n - 1;
        while(leftPtr < rightPtr){
            maxAreaVal = std::max(maxAreaVal, (rightPtr - leftPtr) * std::min(height[leftPtr], height[rightPtr]));
            height[leftPtr] < height[rightPtr] ? leftPtr++ : rightPtr--;
        }
        return maxAreaVal;
    }
};
