class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<char> letters;
        for(char c:s) letters.insert(c);
        int ans=0;
        for(char l:letters){
            int st=-1;
            int en=0;
            for(int i=0;i<s.size();i++){
                if(s[i]==l){
                    if(st==-1) st=i;
                    en=i;
                }
            }
            unordered_set<char> btw;
            for(int i=st+1;i<en;i++) btw.insert(s[i]);
            ans+=btw.size();
        }
        return ans;
    }
};