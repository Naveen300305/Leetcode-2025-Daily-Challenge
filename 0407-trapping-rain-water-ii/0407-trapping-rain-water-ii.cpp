class Solution {
    #define pip pair<int,pair<int,int>>
public:
    bool isvalid(int x, int y, int m,int n){
        return (x>=0 and x<m and y>=0 and y<n);
    }
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m=heightMap.size();
        int n=heightMap[0].size();
        if(m<3 or n<3) return 0;
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        priority_queue<pip,vector<pip>,greater<pip>> minheap;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 or i==m-1 or j==0 or j==n-1){
                    minheap.push(make_pair(heightMap[i][j],make_pair(i,j)));
                    visited[i][j]=true;
                }
            }
        }

        int level=0;
        int trapedwater=0;
        vector<int> dir={-1,0,1,0,-1};

        while(!minheap.empty()){
            pip cur=minheap.top();
            minheap.pop();
            int x=cur.second.first;
            int y=cur.second.second;
            int height=cur.first;
            level=max(level,height);
            for(int i=0;i<4;i++){
                int ux=x+dir[i];
                int uy=y+dir[i+1];
                if(isvalid(ux,uy,m,n) and !visited[ux][uy]){
                    visited[ux][uy]=true;
                    minheap.push(make_pair(heightMap[ux][uy],make_pair(ux,uy)));
                    if(heightMap[ux][uy]<level)
                        trapedwater+=level-heightMap[ux][uy];
                }
            }
        }
        return trapedwater;
    }
};