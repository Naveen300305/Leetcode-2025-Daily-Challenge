class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<pair<int,int>> copy;
        int n=nums.size();
        for(int i=0;i<n;i++){
            copy.push_back(make_pair(nums[i],i));
        }
        sort(copy.begin(),copy.end());
        int left=0,right=1;
        while(right<n){
            vector<int> pos={copy[left].second};
            while(right<n and copy[right].first-copy[right-1].first<=limit){
                pos.push_back(copy[right].second);
                right++;
            }
            sort(pos.begin(),pos.end());
            for(int i=0;i<right-left;i++){
                nums[pos[i]]=copy[left+i].first;
            }
            left=right;
            right++;
        }
        return nums;
    }
};