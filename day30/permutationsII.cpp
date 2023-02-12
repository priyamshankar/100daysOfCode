class Solution {
public:
    void rec(vector<int>& nums, vector<vector<int>>& ans,int ptr, set<vector<int>> &s){
        if(ptr==nums.size()){
            if(s.find(nums)==s.end()){
                ans.push_back(nums);
                s.insert(nums);
            }
            return;
        }
        for(int i=ptr; i<nums.size(); i++){
            swap(nums[i],nums[ptr]);
            rec(nums,ans,ptr+1,s);
            swap(nums[i],nums[ptr]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        set<vector<int>>s;
        rec(nums,ans,0,s);
        return ans;
    }
};