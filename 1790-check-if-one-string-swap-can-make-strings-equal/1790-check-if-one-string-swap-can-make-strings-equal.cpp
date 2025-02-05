class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int diff = 0;
        unordered_map<int,int> mp1,mp2;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]) diff++;
            mp1[s1[i]]++;
            mp2[s2[i]]++;
        }
        if(diff>2) return false;
        else{
            bool ans = true;
            for(auto i:mp1) {
                if(i.second!=mp2[i.first]) return false;
            }
            return true;
        }
        return true;
    }
};