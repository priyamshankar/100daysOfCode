class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int topBound=0,bottomBound=0,leftBound=matrix.size()-1,rightBound=matrix[0].size()-1,i;
        vector<int> ans;
        while(topBound<=leftBound&&bottomBound<=rightBound){
            
            for(i = bottomBound; i<=rightBound&&topBound<=leftBound&&bottomBound<=rightBound; i++){
                ans.push_back(matrix[topBound][i]);
            }
            topBound++;
        
            for(i = topBound; i<= leftBound&&topBound<=leftBound&&bottomBound<=rightBound; i++){
                ans.push_back(matrix[i][rightBound]);
            }
            rightBound--;
            
            for(i = rightBound; i>=bottomBound&&topBound<=leftBound&&bottomBound<=rightBound; i--){
                ans.push_back(matrix[leftBound][i]);
            }
            leftBound--;
           
            for(i = leftBound; i>= topBound&&topBound<=leftBound&&bottomBound<=rightBound; i--){
                ans.push_back(matrix[i][bottomBound]);
            }
            bottomBound++;
          
        }
        return ans;
    }
};