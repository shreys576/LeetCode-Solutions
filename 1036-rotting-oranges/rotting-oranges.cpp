class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        int fresh = 0;

        // Step 1: Push all rotten oranges and count fresh ones
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
                else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }

        if(fresh == 0) return 0;

        int minutes = 0;
        int dRow[4] = {-1, 1, 0, 0};
        int dCol[4] = {0, 0, -1, 1};

        // Step 2: BFS
        while(!q.empty()) {
            int size = q.size();
            bool rottedThisMinute = false;

            for(int i = 0; i < size; i++){
                auto current = q.front();
                q.pop();

                int row = current.first;
                int col = current.second;

                for(int j = 0; j < 4; j++){
                    int newRow = row + dRow[j];
                    int newCol = col + dCol[j];

                    if(newRow >= 0 && newRow < n &&
                       newCol >= 0 && newCol < m &&
                       grid[newRow][newCol] == 1) {

                        grid[newRow][newCol] = 2;
                        q.push({newRow, newCol});
                        fresh--;
                        rottedThisMinute = true;
                    }
                }
            }

            if(rottedThisMinute) minutes++;
        }

        return fresh == 0 ? minutes : -1;
    }
};