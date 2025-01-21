class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int c=grid[0].size();
        if(c==1) return 0;
        vector<long long> ps1(c,0);
        vector<long long> ps2(c,0);
        ps1[0]=0;
        ps2[0]=grid[1][0];
        ps2[c-1]=0;
        for(int i=1;i<c-1;i++){
            ps1[i]=ps1[i-1]+grid[0][i];
            ps2[i]=ps2[i-1]+grid[1][i];
        }
        ps1[c-1]=ps1[c-2]+grid[0][c-1];
        long long ans=LLONG_MAX,s1,s2;
        for(int i=0;i<c;i++){
            s1=ps1[c-1]-ps1[i];
            if(i==0) s2=0;
            else s2=ps2[i-1];
            long long an=max(s1,s2);
            ans=min(ans,an); 
        }
        return ans;
    }
};