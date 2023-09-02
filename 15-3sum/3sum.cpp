class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>> ans;
        int n = nums.size();
        for(int i=0;i<n-2;++i){
            int j=i+1;
            int k=n-1;
            while(j<k){
                if(nums[i]+nums[j]+nums[k]==0){
                    ans.insert({nums[i],nums[j],nums[k]});
                    k--;
                }else if(nums[i]+nums[j]+nums[k]>0){
                    k--;
                }else{
                    ++j;
                }
            }
        }
        vector<vector<int>> temp;
        for(auto k:ans){
            temp.push_back(k);
        }
        return temp;
    }
};