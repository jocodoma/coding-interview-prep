class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // return bruteForce(s);
        // return slidingWindow(s);
        // return slidingWindowOptimal(s);
        // return slidingWindowTable(s);
        return slidingWindowTable2(s);
    }

    // time complexity: O(n^2), in worst case it could be O(n^3)
    // space complexity: O(m), where m is the size of hash set. In worst case it could be up to O(n)
    int bruteForce(string s){
        if(s.empty()) return 0;

        int i, j, maxLength = 0;
        for(i = 0; i < s.length(); i++){
            // find potential substring
            for(j = i + 1; j < s.length(); j++){
                if(s[i] == s[j]) break;
            }

            // check if potential substring has no repeating characters
            std::unordered_set<char> charSet;
            for(int k = i; k < j; k++){
                if(charSet.count(s[k])){
                    j = k;
                    break;
                }
                else{
                    charSet.insert(s[k]);
                }
            }

            maxLength = std::max(maxLength, j - i);
        }
        return maxLength;
    }

    // time complexity: O(2n) = O(n)
    // space complexity: O(m), where m is the size of hash set
    int slidingWindow(string s){
        if(s.empty()) return 0;

        int n = s.length();
        int i = 0, j = 0, maxLength = 0;
        std::unordered_set<char> charSet;

        // window: [i, j]
        while(i < n && j < n){
            if(charSet.count(s[j])){
                charSet.erase(s[i]);
                i++;
            }
            else{
                charSet.insert(s[j]);
                maxLength = std::max(maxLength, j - i + 1);
                j++;
            }
        }
        return maxLength;
    }

    // time complexity: O(n)
    // space complexity: O(m), where m is the size of hash set
    int slidingWindowOptimal(string s){
        if(s.empty()) return 0;

        int n = s.length(), maxLength = 0;
        std::unordered_map<char, int> charMap;

        for(int i = 0, j = 0; j < n; j++){
            // The idea is that if s[j] have a duplicate in the range [i,j) with index j′,
            // we don't need to increase i one by one like above solution.
            // Instead, we can skip all the elements in the range [i,j′] and let i to be j′+1 directly
            if(charMap.count(s[j])){
                i = std::max(i, charMap[s[j]]);
            }
            charMap[s[j]] = j + 1;
            maxLength = std::max(maxLength, j - i + 1);
        }
        return maxLength;
    }

    // time complexity: O(n)
    // space complexity: O(m), where m is the size of table
    int slidingWindowTable(string s){
        if(s.empty()) return 0;
        int n = s.length(), maxLength = 0;

        // int[26] for Letters 'a' - 'z' or 'A' - 'Z'
        // int[128] for ASCII
        // int[256] for Extended ASCII
        std::vector<int> table(256);
        for(int i = 0, j = 0; j < n; j++){
            i = std::max(i, table[s[j]]);
            table[s[j]] = j + 1;
            maxLength = std::max(maxLength, j - i + 1);
        }
        return maxLength;
    }

    int slidingWindowTable2(string s){
        if(s.empty()) return 0;
        int n = s.length(), maxLength = 0;

        std::vector<int> table(256, -1);
        int start = -1;

        for(int i = 0; i < n; i++){
            if(table[s[i]] > start){
                start = table[s[i]];
            }
            table[s[i]] = i;
            maxLength = std::max(maxLength, i - start);
        }
        return maxLength;
    }
};
