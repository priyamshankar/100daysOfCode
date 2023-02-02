class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l=0;  
        int r=nums.size()-1;
        int left=-1,right=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]<target){
                l=mid+1;
            }else if(nums[mid]==target){
                l=mid+1;
                left=l;
                }
            else {
                r=mid-1;
            }
        }
        l=0;  
        r=nums.size()-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]<target){
                l=mid+1;
            }else if(nums[mid]==target){
                r=mid-1;
                right=r;
            }
            else {
                r=mid-1;
            }
        }
        if(left!=-1)left--;
        if(right!=-1)right++;
        if(nums.size()>0 && nums[0]==target){
            right=0;
        }
        
        if (nums.size()>0 && nums[nums.size()-1]==target)left=nums.size()-1;
        return {right,left};
    }
};