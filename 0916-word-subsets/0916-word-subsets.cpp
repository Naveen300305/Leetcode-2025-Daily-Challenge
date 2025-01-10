class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        vector<int> word2(26,0);
        for(auto i:words2){
            vector<int> t(26,0);
            for(int j=0;j<i.size();j++) t[i[j]-'a']++;
            for(int j=0;j<26;j++) word2[j]=max(word2[j],t[j]); 
        }
        for(auto i:words1){
            vector<int> t(26,0);
            for(int j=0;j<i.size();j++) t[i[j]-'a']++;
            int chk=1;
            for(int j=0;j<26;j++){
                if(t[j]<word2[j]){
                    chk=0;
                    break;
                }
            }
            if(chk) ans.push_back(i);
        }
        return ans;
    }

};