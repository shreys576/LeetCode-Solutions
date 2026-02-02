class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> fin;
        int topRow = 0;
        int bottomRow = matrix.size() - 1;
        int leftColumn = 0;
        int rightColumn = matrix[0].size() - 1;

        while(topRow <= bottomRow && leftColumn <= rightColumn){
            for(int i = leftColumn; i <= rightColumn; i++){
                fin.push_back(matrix[topRow][i]);
            }
            topRow++;
            for(int i =topRow; i <= bottomRow; i++){
                fin.push_back(matrix[i][rightColumn]);
            }
            rightColumn--;
            if(topRow <= bottomRow){
                for(int i = rightColumn; i >= leftColumn; i--){
                    fin.push_back(matrix[bottomRow][i]);
                }
                bottomRow--;
            }
            if(leftColumn <= rightColumn){
                for(int i = bottomRow; i >= topRow; i--){
                    fin.push_back(matrix[i][leftColumn]);
                }
                leftColumn++;
            }
        }
        return fin;
    }
};