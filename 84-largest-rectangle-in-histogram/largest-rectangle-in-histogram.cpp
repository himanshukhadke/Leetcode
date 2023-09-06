class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int maxArea = 0;
        int n = arr.size();
        stack<int> s;
        int width;
        for(int i=0;i<=n;++i){
            while(!s.empty() and (i==n or arr[s.top()]>=arr[i])){
                int height = arr[s.top()];
                s.pop();
                if(s.empty()){
                    width=i; 
                }else{
                    width = i-s.top()-1;
                }
                maxArea = max(maxArea, width*height);
            }
            s.push(i);
        }
        return maxArea;
    }
};