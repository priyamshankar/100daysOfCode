class Solution {
public:
    void rec(vector<int> &nums, int target, vector<vector<int>> &ans, vector<int>temp, int sum,int ptr){
        if(sum==target){
            ans.push_back(temp);
            return;
        }
        if(sum>target)return;

        if(ptr==nums.size())return;

        temp.push_back(nums[ptr]);
        rec(nums, target,ans,temp,sum+nums[ptr],ptr+1);
        temp.pop_back();
        while(ptr+1<nums.size() && nums[ptr] == nums[ptr+1])ptr++;

        rec(nums, target,ans,temp,sum,ptr+1);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)    {
        vector<vector<int>> ans;
        sort(candidates.begin(),candidates.end());
        rec(candidates,target,ans,{},0,0);
        return ans;
    }
};