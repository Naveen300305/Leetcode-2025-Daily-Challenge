class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        for(int i=0;i<words.size();i++){
            string s = words[i];
            for(int j=0;j<words.size();j++){
                if(i!=j){
                    if(words[j].find(s)!=string::npos) {
                        ans.push_back(s);
                        break;
                    }
                }
            }
        }
        return ans;
    }
};