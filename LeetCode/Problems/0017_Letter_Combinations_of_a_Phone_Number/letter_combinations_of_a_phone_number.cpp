class Solution {
public:
    vector<string> letterCombinations(string digits) {
        return recursiveMethod(digits);
        // return iterativeMethod(digits);
    }

private:
    vector<string> recursiveMethod(string digits){
        if(digits.empty()) return {};
        len = digits.size();
        search(digits, 0, "");
        return results;
    }

    void search(std::string& digits, int layer, std::string tmpComb){
        if(layer == len){
            results.push_back(tmpComb);
            return;
        }

        int inputNum = digits[layer] - '0';  // subtract '0' due to ASCII
        std::string strLetters = digitMap[inputNum];
        for(int i = 0; i < strLetters.size(); i++){
            search(digits, layer+1, tmpComb + strLetters[i]);
        }
    }

    vector<string> recursiveMethod(string digits){
        if(digits.empty()) return {};
        std::deque<std::string> dq;
        dq.push_back("");
        for(char digit : digits){
            int d = digit - '0';
            int n = dq.size();
            while(n > 0){
                std::string tmpComb = dq.front(); dq.pop_front();
                for(char c : digitMap[d])
                    dq.push_back(tmpComb + c);
                n--;
            }
        }
        return vector<string>(dq.begin(), dq.end());
    }

    std::string digitMap[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    std::vector<std::string> results;
    int len;
};
