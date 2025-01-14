class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> res;
        vector<int> hashA(51,0);
        vector<int> hashB(51,0);
        int ans=0;
        for(int i=0;i<A.size();i++){
            hashA[A[i]]++;
            hashB[B[i]]++;
            if(A[i]==B[i]){
                if(hashA[A[i]]==hashB[B[i]]) ans++;
            }
            else if(A[i]!=B[i]){
                if(hashA[A[i]]==hashB[A[i]]) ans++;
                if(hashA[B[i]]==hashB[B[i]]) ans++;
            }
            res.push_back(ans);
        }
        return res;
    }
};