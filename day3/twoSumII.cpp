// program link: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //solved by two pionter 
        int l=0; 
        int r=nums.size()-1;
        while(l<=r){
            if(nums[l]+nums[r]<target){
                l++;
            }
            else if(nums[l]+nums[r]>target){
                r--;
            }
            else {
                return {l+1,r+1};
            }
        }
        return {};
    }
};