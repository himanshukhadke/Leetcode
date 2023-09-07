class Solution {
public:

    int findWays(vector<int>& arr, int i, int target, int sum){
        if(sum == target and i==-1) return 1;
        if(i<0) return 0;
        return findWays(arr,i-1,target,sum+arr[i]) + findWays(arr,i-1,target,sum-arr[i]);
    }

    int findTargetSumWays(vector<int>& arr, int t) {
        int n = arr.size();
        return findWays(arr,n-1,t,0);
    }
};