class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n,0));
        int topRow = 0;
        int leftColumn = 0;
        int bottomRow = n - 1;
        int rightColumn = n - 1;
        int index = 1;
        while(topRow <= bottomRow && leftColumn <= rightColumn){
            for(int i = leftColumn; i <= rightColumn; i++){
                matrix[topRow][i] = index;
                index++;
            }
            topRow++;
            for(int i =topRow; i <= bottomRow; i++){
                matrix[i][rightColumn] = index;
                index++;
            }
            rightColumn--;
            if(topRow <= bottomRow){
                for(int i = rightColumn; i >= leftColumn; i--){
                    matrix[bottomRow][i] = index;
                    index++;
                }
                bottomRow--;
            }
            if(leftColumn <= rightColumn){
                for(int i = bottomRow; i >= topRow; i--){
                    matrix[i][leftColumn] = index;
                    index++;
                }
                leftColumn++;
            }
        }
        return matrix;
    }
};