class Solution {
public:
    
    
    void dfs(int r, int c, vector<vector<int>> &image, int originalColor, int newColor){
        int n = image.size();
        int m = image[0].size();

        if(r < 0 || r >= n || c < 0 || c >= m) return;

        if(image[r][c] != originalColor)return;

        image[r][c] = newColor;

        // top
        dfs(r - 1, c, image, originalColor, newColor);

        //bottom
        dfs(r + 1, c, image, originalColor, newColor);

        //left
        dfs(r, c - 1, image, originalColor, newColor);

        //right
        dfs(r, c + 1, image, originalColor, newColor);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalColor = image[sr][sc];

        if(originalColor == color) return image;
        // dfs

        dfs(sr,sc,image, originalColor, color);

        return image;
    }
};