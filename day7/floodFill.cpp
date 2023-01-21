class Solution {
public:
vector<vector<int>> rec(vector<vector<int>>& image, int sr, int sc, int color,int rColor){
    if(sc<0 || sr<0 || sr>=image.size() || sc>=image[0].size() || rColor!=image[sr][sc] || image[sr][sc]==color)return image;
        image[sr][sc]=color;
        int x[4]={0,-1,0,1};
        int y[4]={-1,0,1,0};
        for(int i=0; i<4; i++){
            int xt=sr+x[i];
            int yt=sc+y[i];
                rec(image,xt,yt,color,rColor);
        
        }
        return image;
}

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int x=image[sr][sc];
        rec(image,sr,sc,color,x);
        return image;
    }
};