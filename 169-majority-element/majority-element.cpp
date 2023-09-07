class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj=-1;
        int count =0;
        for(auto ele: nums){
            if(count==0){
                maj=ele;
            }
            if(ele==maj) count++;
            else count--;
        }
        return maj;
    }
};