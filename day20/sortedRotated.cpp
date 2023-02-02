// class Solution {
// public:
//     int getMid(vector<int>& nums){
//         int l=0; int r=nums.size()-1;
//         while(l<r){
//             int mid=l+(r-l)/2;
//             cout<<mid;
//             if(nums[mid]>nums[mid+1])return mid+1;
//             if(nums[l]>nums[r]){
//                 l=mid;
//             // }else if(nums[l]<nums[mid]){
//             }else{
//                 r=mid-1;
//             }
//         }
//         return l;
//     }
//     int sh(vector<int>& nums, int target,int l,int r){
//         int index=-1;
//         while(l<=r){
//             int mid=l+(r-l)/2;
//             if(nums[mid]>target){
//                 r=mid-1;
//             }else if(nums[mid]<target){
//                 l=mid+1;
//             }else{
//                 return mid;
//             }
//         }
//         return index;
//     }
//     int search(vector<int>& nums, int target) {
        
//         int mid = getMid(nums);
//         return mid;
//         int i1=sh(nums,target,0,mid-1);
//         int i2=sh(nums,target,mid,nums.size()-1);
//         if(i1==-1)return i2;
//         else return i1;
//         return -1;
//     }
// };

class Solution{
    int solve(vector<int>& nums){
        int start =0;
        int end =nums.size()-1;
        while(start<end){
            int mid  = start+(end-start)/2;
            if(nums[mid]>=nums[0]) start = mid+1;
            else end = mid;
        }
     return start;
    }
    int ans(vector<int>& nums, int target,int start,int end){
        if(end==start ){
            if(target!= nums[start]) return -1 ; 
            return start ;  
        }
        int s =start;
        int e = end;
        if(start<0) return -1;
        if(end>=nums.size()) return -1;
        while(e>=s){
            int mid  =s+(e-s)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>target) e = mid-1;
            else s = mid+1;
        }
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 1 ){
            if(target != nums[0]) return -1 ; 
            return 0 ;  
        }
        int idx = solve(nums);
       if( (nums[0]<=target) && (target<=nums[idx-1])) return ans(nums,target,0,idx-1);
       else if((nums[idx]<=target )&&(target<=nums[nums.size()-1]))
       return ans(nums,target,idx,nums.size()-1);
      else return -1;
    }
};