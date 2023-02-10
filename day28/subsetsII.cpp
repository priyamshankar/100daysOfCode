class Solution {
public:
    void rec(vector<int>& nums,vector<int> temp, vector<vector<int>>&ans,int j){
        if(j==nums.size()){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[j]);
        rec(nums,temp,ans,j+1);
        temp.pop_back();
        while(j+1<nums.size() && nums[j] == nums[j+1])j++;
        
        rec(nums,temp,ans,j+1);
            // rec(nums,temp,ans,j+1);
        // }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        rec(nums,{},ans,0);
        return ans;
    }
};