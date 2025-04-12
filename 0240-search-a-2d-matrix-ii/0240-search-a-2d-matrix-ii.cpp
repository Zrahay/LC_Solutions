class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int row = 0;
        int col = m-1;

        while(row < n && col >-1){
            if(matrix[row][col] == target) return true;

            else if (matrix[row][col] > target) col = col - 1;

            else row = row + 1;

        } 

        return false;
    }
};