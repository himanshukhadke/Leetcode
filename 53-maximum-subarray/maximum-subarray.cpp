class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = -100000;
        int temp = -100000;
        for(auto i :nums){
            temp = max(temp+i,i);
            sum = max(sum, temp);
        }
        return sum ;
    }
};