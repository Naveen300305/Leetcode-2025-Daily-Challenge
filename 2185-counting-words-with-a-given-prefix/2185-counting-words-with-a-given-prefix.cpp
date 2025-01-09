class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans=0;
        int n = pref.size();
        for(int i=0;i<words.size();i++){
            if(words[i].size()>=n){
                int cnt=0;
                for(int j=0;j<n;j++){
                    if(words[i][j]==pref[j]) cnt++;
                    else break;
                }
                ans+=(cnt==n);
            }
        }
        return ans;
    }
};