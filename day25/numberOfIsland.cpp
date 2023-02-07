class Solution {
public:
    void dfs(vector<vector<char>>& grid,vector<vector<bool>>& vis,int col,int row){
        if(col>=grid.size() || col<0 || row >= grid[0].size() || row<0 || grid[col][row] == '0' || vis[col][row]==true)return;
        cout<<col<<"and"<<row<<endl;
        vis[col][row]=true;
        int colptr[4]={0,1,0,-1};
        int rowptr[4]={1,0,-1,0};
        dfs(grid,vis,col,row+1);
        dfs(grid,vis,col+1,row);
        dfs(grid,vis,col,row-1);
        dfs(grid,vis,col-1,row);
        // for(int i=0; i<4; i++){
        //     // if(valid){
        //     dfs(grid,vis,col+colptr[i],row+rowptr[i]);
        //     // }
        // }
    }
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        vector<vector<bool>>vis(grid.size(),vector<bool>(grid[0].size(),false));
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size();j++){
                if(grid[i][j]=='1' && vis[i][j]==false){
                    dfs(grid,vis,i,j);
                    res++;
                }
            }
        }
        return res;
    }
};