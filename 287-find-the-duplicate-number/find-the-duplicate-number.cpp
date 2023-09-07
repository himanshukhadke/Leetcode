class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int low = 1;
        int high = nums.size()-1;
        int ans = -1;
        auto search_less = [&](int num){
            int count=0;
            for(auto k:nums){
                if(k<=num) count++;
            }
            return count;
        };

        while(low<=high){
            int mid = (low+high)/2;
            if(search_less(mid)<=mid){
                low = mid+1; 
            }else{
                ans = mid;
                high = mid-1;
            }
        }
        return ans;
    }
};