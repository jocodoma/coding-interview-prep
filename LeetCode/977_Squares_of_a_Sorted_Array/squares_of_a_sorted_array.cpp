class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        // return solution1(nums);
        return solution2(nums);
    }

    // time complexity: O(nlogn), due to sorting algorithm
    // space complexity: O(1)
    vector<int> solution1(vector<int>& A){
        for(auto& a : A)
            a *= a;
        std::sort(A.begin(), A.end());
        return A;
    }

    // time complexity: O(n)
    // space complexity: O(1)
    vetor<int> solution2(vector<int>& A){
        int l = 0;
        int r = A.size() - 1;
        vector<int> res(A.size());

        for(int i = A.size() - 1; i >= 0; i--)
            res[i] = (std::abs(A[l]) > std::abs(A[r])) ? A[l]*A[l++] : A[r]*A[r--];

        return res;
    }
};
