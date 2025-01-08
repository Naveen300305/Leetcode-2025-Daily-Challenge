class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int ans=0;
        for(int i=1;i<words.size();i++){
            for(int j=i-1;j>=0;j--){
                if(words[i].size()<words[j].size()) continue;
                int cnt1=0,cnt2=0,k=words[i].size()-words[j].size();
                for(int z=0;z<words[j].size();z++) {
                    if(words[i][z]==words[j][z]) cnt1++;
                }                
                for(int z=0;z<words[j].size();z++){
                    if(words[i][k]==words[j][z]) cnt2++;
                    k++;
                }
                if(cnt1==words[j].size() && cnt2==words[j].size()) ans++;
            }
        }
        return ans;
    }
};