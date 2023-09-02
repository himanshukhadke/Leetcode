class Solution {
public:
    int dp[51];
    int func(string &s, int i, vector<string>& dictionary){
        if(i>=s.length()) return 0;
        if(dp[i]!=-1)
            return dp[i];
        int ans = s.length()-i;
        for(int j=i;j<s.length();++j){
            if(find(dictionary.begin(),dictionary.end(),s.substr(i,j-i+1))!=dictionary.end()){
                ans = min( ans, func(s,j+1,dictionary));
            }
            ans = min (ans, j-i+1 + func(s,j+1,dictionary));
        }
        return dp[i]=ans;
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        memset(dp,0,sizeof(dp));
        int n = s.length();
        for(int i=n-1;i>=0;i--){
            int ans = n-i;
            for(int j=i;j<n;++j){
                if(find(dictionary.begin(),dictionary.end(),s.substr(i,j-i+1))!=dictionary.end()){
                    ans = min( ans, dp[j+1]);
                }
                ans = min (ans, j-i+1 + dp[j+1]);
            }
            dp[i] = ans;
        }
        return dp[0];
    }
};