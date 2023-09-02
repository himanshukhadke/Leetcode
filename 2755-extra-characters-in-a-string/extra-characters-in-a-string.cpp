class Solution {
public:
    int dp[51];
    int func(string &s, int i, vector<string>& dictionary){
        if(i>=s.length()) return 0;
        if(dp[i]!=-1)
            return dp[i];
        int ans = s.length()-i;
        for(int j=i;j<s.length();++j){
            // cout<<i<<" "<<j<<endl;
            if(find(dictionary.begin(),dictionary.end(),s.substr(i,j-i+1))!=dictionary.end()){
                //cout<<s.substr(i,j-i+1)<<endl;
                ans = min( ans, func(s,j+1,dictionary));
            }
            ans = min (ans, j-i+1 + func(s,j+1,dictionary));
        }
        return dp[i]=ans;
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        memset(dp,-1,sizeof(dp));
        return func(s, 0, dictionary);
    }
};