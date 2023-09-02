class Solution {
public:
    int arrangeCoins(int n) {
        long long int ans = 0;
        long long int i=1;
        while(1){
            if((i*(i+1))/2<=n){
                ans = i++;
            }else {
                break;
            }
        }
        return ans;
    }
};