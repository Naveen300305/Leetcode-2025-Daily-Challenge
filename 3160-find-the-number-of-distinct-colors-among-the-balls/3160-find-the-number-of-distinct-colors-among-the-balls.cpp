class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int> mp;
        unordered_map<int,int> freq;
        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            if(mp.find(queries[i][0])!=mp.end()){
                if(mp[queries[i][0]]!=queries[i][1]){
                    freq[mp[queries[i][0]]]--;
                    if(freq[mp[queries[i][0]]]==0) freq.erase(mp[queries[i][0]]);
                    freq[queries[i][1]]++;
                    mp[queries[i][0]]=queries[i][1];
                }
            }
            else{
                mp[queries[i][0]]=queries[i][1];
                freq[queries[i][1]]++;
            }
            ans.push_back(freq.size());
        }
        return ans;
    }
};