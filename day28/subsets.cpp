class Solution {
public:
    void rec(vector<int>& nums,vector<int> temp, vector<vector<int>>&ans,int j){
        if(j==nums.size()){
            ans.push_back(temp);
            return;
        }
        // int j=i;
        // for(int j=i;j<nums.size(); j++){
            rec(nums,temp,ans,j+1);
            temp.push_back(nums[j]);
            rec(nums,temp,ans,j+1);
        // }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        rec(nums,{},ans,0);
        return ans;
    }
};