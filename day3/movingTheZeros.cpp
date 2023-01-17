//problem link: https://leetcode.com/problems/move-zeroes/?envType=study-plan&id=algorithm-i
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int z=0; 
        for(int i=0; i<nums.size(); i++){
            if(nums[z]==0 && nums[i]!=0){
                swap(nums[z],nums[i]);
                z++;
            }
            if(nums[i]!=0){
                 z++;     
            }
        }
        
    }
};