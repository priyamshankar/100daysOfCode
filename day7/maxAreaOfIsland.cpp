
//program link : https://leetcode.com/problems/max-area-of-island/description/?envType=study-plan&id=algorithm-i

class Solution {
public:
    void rec(vector<vector<int>>& grid,int row,int col,vector<vector<int>>&vis,int &count){
        if(row<0 || col < 0 || row>=grid.size() || col>= grid[0].size() || vis[row][col]!=0 || grid[row][col]==0)return;
// cout<<"ab";
        vis[row][col]=1;
        count++;
        int x[4]={0,-1,0,1};
        int y[4]={-1,0,1,0};
        for(int i=0; i<4; i++){
            rec(grid,row+x[i],col+y[i],vis,count);
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<int>>visited(grid.size(),vector<int>(grid[0].size(),0));
        int maxm=0;
        int count=0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(visited[i][j]==0 && grid[i][j]==1){
                    rec(grid,i,j,visited,count);
                    maxm=max(count,maxm);
                    cout<<count<<",";
                    count=0;
                }
            }
        }
        return maxm;
    }
};