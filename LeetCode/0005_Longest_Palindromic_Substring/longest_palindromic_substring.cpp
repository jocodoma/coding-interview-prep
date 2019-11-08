
class Solution {
public:
    string longestPalindrome(string s) {
        // return dynamicProgramming(s);
        return dynamicProgrammingOptimal(s);
    }

    // The simple approach (brute force) is to check each substring whether the substring
    // is a palindrome or not. We can run three loops, the outer two loops pick all substrings
    // one by one by fixing the corner characters, the inner loop checks whether the picked substring 
    // is palindrome or not.
    // -> time complexity: O(n^3), space complexity: O(1)

    // Dynamic Programming
    // Reference: https://leetcode.com/problems/longest-palindromic-substring/solution/
    // Reference: https://youtu.be/TLaGwTnd3HY
    // time complexity: O(n^2), space complexity: O(n^2)
    string dynamicProgramming(string s){
        if(s.size() < 2) return s;

        int n = s.size();
        int startIdx = 0, maxLength = 1;  // All substrings of length 1 are palindromes
        bool p[n][n] = {false};

        // Base case 1, p[i][i] is true
        for(int i = 0; i < n; i++)
            p[i][i] = true;
            // startIdx = 0;
            // maxLength = 1;

        // Base case 2, p[i][i+1] is true
        for(int i = 0; i < n - 1; i++){
            if(s[i] == s[i+1]){
                p[i][i+1] = true;
                startIdx = i;
                maxLength = 2;
            }
        }

        // if p[i+1][j-1] is true and s[i] == s[j]
        // then p[i][j] is also true
        for(int diff = 2; diff < n; diff++){
            for(int i = 0; i < n - diff; i++){
                int j = i + diff;
                if(p[i+1][j-1] && s[i] == s[j]){
                    p[i][j] = true;
                    startIdx = i;
                    maxLength = diff + 1;  // diff is 0-based index, maxLength is 1-based index
                }
            }
        }

        return s.substr(startIdx, maxLength);
    }

    // time complexity: O(n^2), space complexity: O(1)
    string dynamicProgrammingOptimal(string s){
        if(s.size() < 2) return s;

        int n = s.size();
        int maxLength = 0, startIdx = 0;
        int i = 0;
        while(i < n){
            int leftIdx = i, rightIdx = i;

            // find the middle of a palindrome
            while(rightIdx < n-1 && s[rightIdx] == s[rightIdx+1]) rightIdx++;

            i = rightIdx + 1;

            // expand from the middle out
            while(leftIdx > 0 && rightIdx < n-1 && s[leftIdx-1] == s[rightIdx+1]){
                leftIdx--;
                rightIdx++;
            }

            int newLength = rightIdx - leftIdx + 1;
            if(newLength > maxLength){
                startIdx = leftIdx;
                maxLength = newLength;
            }
        }
        return s.substr(startIdx, maxLength);
    }
};
