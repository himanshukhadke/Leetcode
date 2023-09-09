class Solution {
public:

    int dp[1001];

    int func(vector<int>& nums, int target, string temp){
        if(target==0){
            // cout<<temp<<" ";
            return 1;
        } 
        if(target<0) return 0;
        if(dp[target]!=-1) return dp[target];
        int ans = 0;
        for(int i=0;i<nums.size();++i){
            ans+=func(nums,target-nums[i],temp+to_string(nums[i]));
        }
        return dp[target]=ans;
    }

    int combinationSum4(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        return func(nums,target,"");
    }
};