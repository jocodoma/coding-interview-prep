class Solution {
public:
    vector<string> generateParenthesis(int n) {
        return recursiveMethod(n);
        // return iterativeMethod(n);
    }

private:
    vector<string> recursiveMethod(int n){
        if(!n) return {};
        int numOpen = 0, numClose = 0;
        std::string tmp;
        generate(n, numOpen, numClose, tmp);
        return result;
    }

    void generate(int n, int numOpen, int numClose, std::string tmp){
        if(numOpen == n && numClose == n){
            result.push_back(tmp);
            return;
        }
        if(numOpen < n)
            generate(n, numOpen+1, numClose, tmp+"(");
        
        if(numClose < numOpen)
            generate(n, numOpen, numClose+1, tmp+")");
    }

    std::vector<std::string> result;

    vector<string> iterativeMethod(int n){
        if(!n) return {""};

        std::vector<std::string> ans;
        for(int i = 0; i < n; i++)
            for(std::string l : iterativeMethod(i))
                for(std::string r : iterativeMethod(n-1-i))
                    ans.push_back("("+l+")"+r);

        return ans;
    }
};
