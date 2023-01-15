//problem link https://leetcode.com/problems/binary-search/?envType=study-plan&id=algorithm-i

class Solution {
public:
    int search(vector<int>& nums, int target) {
    /* new code for now*/
    int l=0; 
    int r=nums.size()-1;
    while(l<=r){
        int mid = l+(r-l)/2;
        if(nums[mid]<target){
            l=mid+1;
        }else if(nums[mid]>target){
            r=mid-1;
        }else {
            return mid;
        }
    }
    return -1;
}

};