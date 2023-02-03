class Solution {
public:
    int getMid(vector<int>& nums){
        int l=0; int r=nums.size()-1;
        
        while(l<r){
            int mid=l+(r-l)/2;
            // cout<<mid;
            if(nums[mid]>=nums[0]){
                l=mid+1;
            }else{
                r=mid;
            }
        }
        return l;
    }
    int sh(vector<int>& nums, int target,int l,int r){
        int index=-1;
        if(nums[l]==target){
            return l;
        }
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]>target){
                r=mid-1;
            }else if(nums[mid]<target){
                l=mid+1;
            }else{
                return mid;
            }
        }
        return index;
    }
    int search(vector<int>& nums, int target) {
        
        int mid = getMid(nums);
        cout<<mid;
        if(nums.size()==2){
            if(nums[0]>nums[1]){
                mid=1;
            }
        }
        // return mid;
        int i1=sh(nums,target,0,mid-1);
        int i2=sh(nums,target,mid,nums.size()-1);
        if(i1==-1)return i2;
        else return i1;
        return -1;
    }
};
