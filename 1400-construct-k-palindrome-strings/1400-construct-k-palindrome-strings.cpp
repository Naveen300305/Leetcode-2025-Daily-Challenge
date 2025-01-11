class Solution {
public:
    bool canConstruct(string s, int k) {
        unordered_map<char,int> mp;
        if(k>s.size()) return false;
        for(char i:s){
            mp[i]++;
        }
        int odcnt=0;
        int evc=0;
        for(auto i:mp){
            if(i.second%2==1) odcnt++;
            //if(i.second>2 && i.second%2==0) evcnt++; 
        }
        if(odcnt>k) return false;
        return true;
    }
};