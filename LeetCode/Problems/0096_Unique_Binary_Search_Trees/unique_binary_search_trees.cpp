class Solution {
public:
    int numTrees(int n) {
        return catalanNumber(n);
        return symmetry(n);
    }

    // https://www.quora.com/Given-n-how-many-structurally-unique-BSTs-binary-search-trees-that-store-values-1-to-n-are-there-How-would-I-come-up-with-the-solution-Can-you-explain-the-thought-process-that-leads-to-the-solution#
    // https://leetcode.com/problems/unique-binary-search-trees/discuss/31813/0ms-easy-to-understand-solution-in-C%2B%2B

    int catalanNumber(int n){
        if(n == 0) return 0;

        vector<int> nums;
        nums.push_back(1);

        for(int i = 1; i <= n; i++){
            int num = 0;
            for(int j = 1; j <= i; j++){
                num += nums[j-1] * nums[i-j];
            }
            nums.push_back(num);
        }

        return nums.back();
    }

    // https://leetcode.com/problems/unique-binary-search-trees/discuss/31815/A-0-ms-c%2B%2B-solution-with-my-explanation
    // set t[0]=1; just for easy calculation.
    // t[1]=1, means when there is one node, return 1.
    // When n=2, {1,2}:
    // If '1' is root, there is 0 node left to build up left branch, and 1 node left to build up right branch. Thus when n=2, '1' is root, there are t[0] * t[1] trees.
    // If '2' is root, there is 1 node to build left branch, and 0 node to build right branch. Thus n=2, '2' is root, there are t[1] * t[0] trees.
    // So when n=2, there are t[0]*t[1] + t[1]*t[0]; trees.
    // Use the 'root' to divide 1...n into two parts, then there are t[remaining number of left] * t[remaining number of right] trees for each 'root'.

    int symmetry(int n){
        vector<int> nums(n+1);
        nums[0] = nums[1] = 1;

        for(int i = 2; i <= n; i++){
            for(int j = 1; j <= i/2; j++){
                nums[i] += nums[j-1] * nums[i-j];
            }
            nums[i] *= 2;
            if(i % 2){
                nums[i] += nums[i/2] * nums[i/2];
            }
        }

        return nums[n];
    }
};
