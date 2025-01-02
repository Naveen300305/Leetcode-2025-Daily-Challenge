class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n=queries.size();
        int m=words.size();
        int k=words[0].size();
        string vow="aeiou";
        vector<int> ans(n,0);
        vector<int> ps(m,0);
        if(vow.find(words[0][0])!=string::npos && 
           vow.find(words[0][k-1])!=string::npos){
            ps[0]=1;
        }
        for(int i=1;i<m;i++){
            int k=words[i].size();
            if(vow.find(words[i][0])!=string::npos && vow.find(words[i][k-1])!=string::npos)
            ps[i]=1+ps[i-1];
            else ps[i]=ps[i-1];
        }
        for(int i=0;i<n;i++){
            if(queries[i][0]==0) ans[i]=ps[queries[i][1]];
            else ans[i]=ps[queries[i][1]]-ps[queries[i][0]-1];
        }
        return ans;
    }
};