class Solution {
public:
    
    void dfs(int city, vector<vector<int>> &isConnected, vector<bool> &isVisited){
        // mark the current city as visited
        isVisited[city] = true;

        for(int i = 0; i < isConnected.size(); i++){
            if(isConnected[city][i] == 1 && !isVisited[i]){
                dfs(i, isConnected, isVisited);
            }
        }
    }
    
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> isVisited(n, false);
        int ProvinceCount = 0;

        //Loop over all the cities
        for(int i = 0; i<n; i++){
            if(!isVisited[i]){
                dfs(i, isConnected, isVisited);
                ProvinceCount++;
            }
        }
        return ProvinceCount;
    }
};