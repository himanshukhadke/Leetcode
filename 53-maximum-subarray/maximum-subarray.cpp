class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=INT_MIN;
        int temp=0;
        for(auto k:nums){
            temp = max (temp+=k, k);
            ans = max(temp,ans);
        }
        return ans;
    }
};