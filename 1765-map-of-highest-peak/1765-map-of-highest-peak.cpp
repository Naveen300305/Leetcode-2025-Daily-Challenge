class Solution {
    bool isvalid(int x,int y,int m,int n){
        return (x>=0 and x<m and y>=0 and y<n);
    }
public:
    #define pii pair<int,int>
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m=isWater.size();
        int n=isWater[0].size();
        vector<vector<int>> heights(m,vector<int>(n,0));
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        queue<pii> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(isWater[i][j]==1){
                    visited[i][j]=true;
                    q.push({i,j});
                    heights[i][j]=0;
                }
            }
        }
        int level=0;
        int dir[]={-1,0,1,0,-1};
        while(!q.empty()){
            int s=q.size();
            for(int j=0;j<s;j++){
                pii cur=q.front();
                q.pop();
                int x=cur.first,y=cur.second;
                for(int i=0;i<4;i++){
                    int nx=x+dir[i],ny=y+dir[i+1];
                    if(isvalid(nx,ny,m,n) and !visited[nx][ny]){
                        heights[nx][ny]=level+1;
                        q.push({nx,ny});
                        visited[nx][ny]=true;
                    }
                }
            }
            level++;
        }
        return heights;
    }
};