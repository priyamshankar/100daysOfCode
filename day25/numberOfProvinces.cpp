// class Solution {
// public:
//     void bfs(vector<vector<int>>& isConnected,vector<vector<int>>& vis,int col,int row){
//         if(col>=isConnected.size() || col<0 || row >= isConnected[0].size() || row<0 || isConnected[col][row] == 0 || vis[col][row]==1){
//             if(row!=0)
//                 return;
//             }     
        
//         vis[col][row]=1;
//         for(int i=0; i<isConnected[0].size(); i++){
//             bfs(isConnected,vis,col,row+i);
//             bfs(isConnected,vis,row+i,0);        
//         }
//     }
//     int findCircleNum(vector<vector<int>>& isConnected) {
//         vector<vector<int>> vis(isConnected.size(),vector<int>(isConnected[0].size(),0));
//         int res=0;
//         for(int i=0; i<isConnected.size(); i++){
//             for(int j=0; j<isConnected[0].size();j++){
//                 if(isConnected[i][j]==1 && vis[i][j]==0){
//                     bfs(isConnected,vis,i,j);
//                     res++;
//                 }
//             }
//         }
//         return res;
//     }
// };

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();
        int res = 0;
        int node;
        for(int i=0;i<n;i++)
        {
            if(isConnected[i][i]!=1)continue;  
            queue<int>Q;
            Q.push(i);
            while(!Q.empty())
            {
                node = Q.front();
                Q.pop();
                
                isConnected[node][node]=2;
                for(int j=0; j<n; j++)
                {
                    if(isConnected[node][j]==1)
                    {
                        Q.push(j);
                        isConnected[node][j]=2;
                        isConnected[j][node]=2;
                    }                    
                }

            }
            res++;
        }
            
        return res;
    }
};