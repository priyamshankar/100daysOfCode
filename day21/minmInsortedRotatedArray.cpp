class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0; int r=nums.size()-1;
        if(nums.size()==1)return nums[0];
        int ans=INT_MAX;
        while(l<r){
            int mid=l+(r-l)/2;
            // cout<<nums[l];            
            ans=min(ans,nums[l]);
            if(nums[mid]>=nums[0]){
                l=mid+1;
            }else{
                r=mid;
            }
        }
        ans=min(ans,nums[l]);
        // cout<<nums[l];
        return ans;
    }
};