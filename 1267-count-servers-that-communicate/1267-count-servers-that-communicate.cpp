class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int ans=0;
        int m=grid.size(),n=grid[0].size();
        unordered_map<int,int> row;
        unordered_map<int,int> col;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    row[i]++;
                    col[j]++;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 and (row[i]>1 or col[j]>1)) ans++;
            }
        }
        return ans;
        
    }
};