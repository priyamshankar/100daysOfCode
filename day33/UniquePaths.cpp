class Solution {
public:
    int rec(int m,int n,int &count,int c, int r,vector<vector<int>>&vis){
        if(c<0 || r<0 || c>=m || r>=n){
            return 0;
        }
        if(c==m-1 && r==n-1){
            // count++;
            return 1;
        }
        if(vis[c][r]!=-1){
            // count++;
            return vis[c][r];
        }
        // vis[c][r]=1;
        int left = rec(m,n,count,c+1,r,vis);
        int down = rec(m,n,count,c,r+1,vis);
        return vis[c][r] = left+down;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>vis(m+1,vector<int>(n+1,-1));
        int count=0;
        return rec(m,n,count,0,0,vis);
        // return count;
    }
};