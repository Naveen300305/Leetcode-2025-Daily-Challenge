class Solution {
public:
    int maxScore(string s) {
        int ans=0,n=s.size();
        int cl=0,cr=0;
        if(s[0]=='0') cl++;
        for(int i=1;i<n;i++){
            if(s[i]=='1') cr++;
        }
        ans=max(ans,cr+cl);
        for(int i=1;i<n-1;i++){
            if(s[i]=='0') cl++;
            else cr--;
            ans=max(ans,cr+cl);
        }
        return ans;
    }
};