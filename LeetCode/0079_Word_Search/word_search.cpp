class Solution {
public:
    // time complexity: O(m*n*l), space complexity: O(1)
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size() == 0 || board[0].size() == 0)
            return true;
        
        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < board[0].size(); j++)
                if(check(board, word, i, j)) return true;

        return false;
    }

private:
    bool check(vector<vector<char>>& board, string word, int i, int j){
        if(word.length() == 0)  // end condition
            return true;

        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size())  // boundary check
            return false;

        if(word[0] != board[i][j])  // not match
            return false;

        char c = word[0];
        board[i][j] = '\0';  // avoid duplicated search

        bool isFound = check(board, word.substr(1), i+1, j)  // up
            || check(board, word.substr(1), i-1, j)  // down
            || check(board, word.substr(1), i, j+1)  // right
            || check(board, word.substr(1), i, j-1);  // left

        board[i][j] = c;

        return isFound;
    }
};
