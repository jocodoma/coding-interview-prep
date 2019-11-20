class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        return sortedStringHashMap(strs);
    }

    // time complexity: O(nklogk), where n is the length of arrary and k is the maximum length of string
    // space complexity: O(nk)
    vector<vector<string>> sortedStringHashMap(vector<string>& strs){
        if(strs.empty()) return {{}};

        unordered_map<std::string, std::vector<std::string>> map;
        for(const auto& str : strs){
            std::string sortedStr = str;
            std::sort(sortedStr.begin(), sortedStr.end());  // O(klogk)
            map[sortedStr].push_back(str);
        }
        std::vector<std::vector<std::string>> anagrams;
        for(const auto& it : map){
            anagrams.push_back(it.second);
        }
        return anagrams;
    }
};
