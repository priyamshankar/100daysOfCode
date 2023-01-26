// class Solution {
// public:

//     int rec(vector<vector<int>> mat,vector<vector<int>>&ans, int r, int c,vector<vector<int>>&v){
//         if(c<0 || r<0 || c>=mat[0].size() || r>=mat.size() ){
//             return 100000;
//         }
//         if(mat[r][c]==0){
//             // v[r][c]==1;
//             // ans[r][c]=0;
//             return 1;
//         }
//         if(ans[r][c]!=-1){
//             return ans[r][c]+1;
//         }
      
//         if(v[r][c]==1){
//             // return ans[r][c]+1;
//             return 100000;
//         }
//         v[r][c]=1;
//         int rx[4]={-1,0,1,0};
//         int cx[4]={0,1,0,-1};
//         int maxm=INT_MAX;
//         for(int i=0; i<4; i++){
//             int m=rec(mat,ans,r+rx[i],c+cx[i],v);
//             // if(m!=-1)
//                 maxm=min(m,maxm);
//                 m=0;
//         }
//         ans[r][c]=maxm;
//         // if(maxm==INT_MAX)return -1;
//         return maxm+1;
//     }

//     vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
//         vector<vector<int>>ans(mat.size(),vector<int>(mat[0].size(),-1));
//         vector<vector<int>>v(mat.size(),vector<int>(mat[0].size(),0));
//         for(int i=0; i<mat.size(); i++){
//             for(int j=0; j<mat[0].size(); j++){
//                 if(ans[i][j]==-1 && mat[i][j]==1 && v[i][j]==0){
//                 rec(mat,ans,i,j,v);
//                 }else if(mat[i][j]==0){
//                     ans[i][j]=0;
//                 }
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0)
                    q.push({i,j});
                else
                    grid[i][j]=-1;
            }
        }
        vector<int> d={-1,0,1,0,-1};
        while(!q.empty())
        {
            int sz=q.size();
            for(int i=0;i<sz;i++)
            {
                pair<int,int> p=q.front();
                q.pop();
                for(int j=0;j<4;j++)
                {
                    int r=p.first+d[j];
                    int c=p.second+d[j+1];
                    if(r>=0 && c>=0 && r<m && c<n && grid[r][c]==-1)
                    {
                        grid[r][c]=1+grid[p.first][p.second];
                        q.push({r,c});
                    }
                }
            }
        }
        return grid;
    }
};