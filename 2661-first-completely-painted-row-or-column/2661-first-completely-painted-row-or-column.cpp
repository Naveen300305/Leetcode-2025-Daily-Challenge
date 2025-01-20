class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int,pair<int,int>> rc;
        int m=mat.size();
        int n=mat[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                rc[mat[i][j]]={i,j};
            }
        }
        unordered_map<int,int> row;
        unordered_map<int,int> col;
        for(int i=0;i<arr.size();i++){
            row[rc[arr[i]].first]++;
            col[rc[arr[i]].second]++;
            if(row[rc[arr[i]].first]==n || col[rc[arr[i]].second]==m) return i;
        }
        return n*m;
    }
};