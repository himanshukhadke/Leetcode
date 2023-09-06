class Solution {
public:
    int x[4] = {1,0,-1,0};
    int y[4] = {0,1,0,-1};
    
    void dfs(int i,int j, int n, int m, vector<vector<char>>& grid){
        grid[i][j] = '0';
        for(int a=0;a<4;++a){
            int row = i + x[a];
            int col = j + y[a]; 
            if(row>=0 and col>=0 and row<n and col<m and grid[row][col]=='1'){
                dfs(row,col,n,m,grid);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans=0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j]=='1'){
                    ++ans;
                    dfs(i,j,n,m,grid);
                }
            }
        }
        return ans;
    }
};