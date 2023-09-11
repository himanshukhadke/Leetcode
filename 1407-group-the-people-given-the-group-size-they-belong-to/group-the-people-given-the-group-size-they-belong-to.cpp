class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& arr) {
        unordered_map<int,vector<int>> mp;
        vector<vector<int>> ans;
        int n = arr.size();
        for(int i=0;i<n;++i){
            mp[arr[i]].push_back(i);
        }
        vector<int> temp;
        for(auto k:mp){
            int size = k.first;
            int len = k.second.size();
            cout<<size<<" "<<len<<endl;
            temp.clear();
            int tempsize = size;
            while(k.second.size()>0){
                temp.push_back(k.second.front());
                k.second.erase(k.second.begin());
                tempsize--;
                if(tempsize==0){
                    ans.push_back(temp);
                    tempsize=size;
                    temp.clear();
                }
            }
        }
        return ans;
    }
};