class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int l=0,r=1,n=nums.size();
        int ans = nums[0] , temp = nums[0];
        while(r<n){
            temp+=nums[r];
            if(nums[r-1]>nums[r]){
                temp=nums[r];
                l=r;
            }
            r++;
            ans=max(ans,temp);
        }
        return ans;
    }
};