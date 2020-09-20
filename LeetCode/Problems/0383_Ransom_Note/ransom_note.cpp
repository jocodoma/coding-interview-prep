class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        return bruteForce(ransomNote, magazine);
        return hashMap(ransomNote, magazine);
    }

    // n is the size of ransomNote, m is the size of magazine
    // time complexity: O(n*m), space complexity: O(1)
    bool bruteForce(std::string ransomNote, std::string magazine){
        for(char c : ransomNote){
            auto found = magazine.find(c);
            if(found == std::string::npos)
                return false;
            else
                magazine[found] = ' ';
        }
        return true;
    }

    // time complexity: O(n+m), space complexity: O(m)
    bool hashMap(std::string ransomNote, std::string magazine){
        std::unordered_map<char, int> magMap;

        for(int i = 0; i < magazine.size(); i++)
            magMap[magazine[i]]++;

        for(int i = 0; i < ransomNote.size(); i++)
            if(--magMap[ransomNote[i]] < 0)
                return false;

        return true;
    }
};


