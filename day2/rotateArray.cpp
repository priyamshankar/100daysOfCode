
//Problem link :https://leetcode.com/problems/rotate-array/submissions/860784206/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        if(k==nums.size())return;
        vector<int>v(nums.size(),0);

        if(k>nums.size()){
            k=k%nums.size();
        }
        int h=nums.size()-k;
        for(int i=0; i<nums.size(); i++){
            if(h>=nums.size())h=0;
            v[i]=nums[h];
            h++;
        }
        for(int i=0; i<nums.size();i++){
            nums[i]=v[i];
        }
    }
};