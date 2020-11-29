#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    Solution() {}
    int lengthOfLongestSubstring(string s) {
        // return bruteForce(s);
        // return slidingWindow(s);
        return slidingWindowOptimal(s);
        // return slidingWindowTable(s);
        // return slidingWindowTable2(s);
    }

private:
    // time complexity: O(n^2), in worst case O(n^3) due to the search in the hashset
    // space complexity: O(m), where m is the size of hash set. In worst case it could be up to O(n)
    int bruteForce(string s) {
        int maxLength = 0;
        int n = s.length();

        for (int i = 0, j = 0; i < n; i++) {
            for(j = i + 1; j < n; j++) {
                if(s[i] == s[j])
                    break;
            }

            // potential substring [i, j)
            std::unordered_set<char> charSet;
            for (int k = i; k < j; k++) {
                if(charSet.count(s[k])){
                    j = k;
                    break;
                }

                charSet.insert(s[k]);
            }

            maxLength = std::max(maxLength, j - i);
        }

        return maxLength;
    }

    // time complexity: O(n), in worst case O(n^2) due to the search in the hashset
    // space complexity: O(m), where m is the size of hash set
    int slidingWindow(string s) {
        int maxLength = 0;
        int n = s.size();
        int i = 0, j = 0;
        std::unordered_set<char> charSet;

        while (i < n && j < n) {
            if (charSet.count(s[j])) {
                charSet.erase(s[i]);
                i++;
            }
            else {
                charSet.insert(s[j]);
                j++;
            }

            maxLength = std::max(maxLength, j - i);
        }

        return maxLength;
    }

    // time complexity: O(n), in worst case O(n^2) due to the search in the hashset
    // space complexity: O(m), where m is the size of hash map
    int slidingWindowOptimal(string s) {
        int maxLength = 0;
        int n = s.length();
        std::unordered_map<char,int> charMap;

        for (int i = 0, j = 0; j < n; j++) {
            // The idea is that if s[j] have a duplicate in the range [i,j) with index j′,
            // we don't need to increase i one by one like above solution.
            // Instead, we can skip all the elements in the range [i,j′] and let i to be j′+1 directly

            if (charMap.count(s[j]))
                i = std::max(i, charMap[s[j]]);

            charMap[s[j]] = j + 1;
            maxLength = std::max(maxLength, j + 1 - i);
        }

        return maxLength;
    }


    // time complexity: O(n)
    // space complexity: O(m), where m is the size of table
    int slidingWindowTable(string s){
        int maxLength = 0;
        int n = s.length();

        // int[26] for Letters 'a' - 'z' or 'A' - 'Z'
        // int[128] for ASCII
        // int[256] for Extended ASCII
        vector<int> table(256);

        for(int i = 0, j = 0; j < n; j++){
            i = std::max(i, table[s[j]]);
            table[s[j]] = j + 1;
            maxLength = std::max(maxLength, j + 1 - i);
        }
        return maxLength;
    }

    // same as above
    int slidingWindowTable2(string s){
        int maxLength = 0;
        int n = s.length();

        vector<int> table(256, -1);
        int start = -1;

        for(int i = 0; i < n; i++){
            if(table[s[i]] > start)
                start = table[s[i]];

            table[s[i]] = i;
            maxLength = std::max(maxLength, i - start);
        }
        return maxLength;
    }
};

int main() {
    Solution sol;

    cout << "Output: " << sol.lengthOfLongestSubstring("abcabcbb") << "\n";
    cout << "Output: " << sol.lengthOfLongestSubstring("bbbbb") << "\n";
    cout << "Output: " << sol.lengthOfLongestSubstring(" ") << "\n";
    cout << "Output: " << sol.lengthOfLongestSubstring("pwwkew") << "\n";

    return 0;
}
