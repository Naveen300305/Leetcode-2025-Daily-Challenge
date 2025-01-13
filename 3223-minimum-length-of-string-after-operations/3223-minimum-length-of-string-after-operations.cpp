class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,int> mp;
        for(char i:s){
            mp[i]++;
        }
        int ans=0;
        for(auto i:mp){
            if(i.second%2==0) ans+=2;
            else ans+=1;
        }
        return ans;
    }
};