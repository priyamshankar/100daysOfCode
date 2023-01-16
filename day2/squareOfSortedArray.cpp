class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int l=0; int r=nums.size()-1;
        int tr=r;
        int tl=l;
        vector<int>v(nums.size(),0);
        while(l<=r){
            int tempL=nums[l]*nums[l];
            int tempR=nums[r]*nums[r];
            if(tempL>=tempR){
                v[tr]=tempL;
                l++;
                tr--;
            }
            else{
                v[tr]=tempR;
                r--;
                tr--;
            }
        }
        return v;
    }
};