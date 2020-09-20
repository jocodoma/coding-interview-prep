class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        return solution1(matrix);
        // return solution2(matrix);
    }

    void solution1(vector<vector<int>>& matrix){
        int n = matrix.size();
        // (i,j) -> (j,i) -> (j,N-i-1)
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }

        for(int i = 0; i < n; i++)
            std::reverse(matrix[i].begin(), matrix[i].end());
    }

    void solution2(vector<vector<int>>& matrix){
        int n = matrix.size();
        // clockwise rotation : matrix[j][n-1-i] = matrix[i][j]
        std::reverse(matrix[i].begin(), matrix[i].end());
        // transpose of the matrix: matrix[i][j] = matrix[j][i];
        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++)
                std::swap(matrix[i][j], matrix[j][i]);
    }
};
