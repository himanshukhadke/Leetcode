class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int maj1=-1,maj2=-1,c1=0,c2=0;
        int n=nums.size();
        for(int i=0; i<nums.size(); ++i){
            if(nums[i]==maj1){
                ++c1;
            }else if(nums[i]==maj2){
                ++c2;
            }else if(c1==0){
                maj1=nums[i];
                c1=1;
            }else if(c2==0){
                maj2=nums[i];
                c2=1;
            }else{
                --c1;
                --c2;
            }
        }
        vector<int> ans;
        c1=0,c2=0;
        for(int i=0; i<nums.size(); ++i){
            if(nums[i]==maj1)++c1;
            if(nums[i]==maj2)++c2;
        }
        if(c1>n/3) ans.push_back(maj1);
        if(c2>n/3 and maj1!=maj2) ans.push_back(maj2);
        return ans;
    }
};