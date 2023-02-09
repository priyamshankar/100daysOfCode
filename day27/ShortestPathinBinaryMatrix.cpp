class Solution {
public:
    void dfs (vector<vector<int>> &grid,vector<vector<int>>& vis,int col, int row,int ans,int &maxm,int maxCol,int maxRow){
        if(row<0 || col < 0 || row>maxRow || col > maxCol  || grid[col][row]==1 || vis[col][row]==1){
            return;
        }
        if(grid[0][0] || grid[maxCol][maxRow] ) return ;
        if(row==maxRow && col==maxCol){
            maxm=min(maxm,ans);
            return;
        }
        vis[col][row]=1;
        int colPtr[8]={-1,-1,-1,0,0,1,1,1};
        int rowPtr[8]={-1,0,1,-1,1,-1,0,1};

        for(int i=0 ;i<8; i++){
            dfs(grid,vis,col+colPtr[i],row+rowPtr[i],ans+1,maxm,maxCol,maxCol);
        }
        vis[col][row]=0;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int ans=INT_MAX;
        int maxRow=grid[0].size()-1;
        int maxCol=grid.size()-1;
        vector<vector<int>>vis(maxCol+1,vector<int>(maxRow+1,0));   
        int row=0; int col=0; int temp=0;     
        dfs(grid,vis,col,row,temp,ans,maxCol,maxRow);
        if(ans==INT_MAX)return -1;
        return ans+1;
    }
};