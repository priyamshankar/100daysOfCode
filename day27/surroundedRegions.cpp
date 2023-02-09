class Solution {
public:
    void dfs(vector<vector<char>>& board,vector<vector<int>>& vis, int row, int col){
        if(row<0 || col < 0 || row>=board[0].size() || col >= board.size() || vis[col][row]==1 || board[col][row]=='X'){
            return;
        }
        vis[col][row]=1;
        int colPtr[4]={0,-1,0,1};
        int rowPtr[4]={1,0,-1,0};

        for(int i=0 ;i<4; i++){
            board[col][row]='p';
            dfs(board,vis,row+rowPtr[i],col+colPtr[i]);
        }
        
    }
    void solve(vector<vector<char>>& board) {
        vector<vector<int>>vis(board.size(),vector<int>(board[0].size(),0));
        for(int i=0 ;i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if((j==0 || j==board[0].size()-1)){
                    dfs(board,vis,j,i);
                }
            }
        }
        for(int i=0; i<board[0].size(); i++){
            dfs(board,vis,i,0);
            dfs(board,vis,i,board.size()-1);
        }
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j]=='p')board[i][j]='O';
                else if(board[i][j]=='O')board[i][j]='X';
            }
        }
    }
};