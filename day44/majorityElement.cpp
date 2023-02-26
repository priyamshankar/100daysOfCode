class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        sort(nums.begin(),nums.end());
        int ans=0;
        int count=1; 
        int maxm=INT_MIN;
        for (int i=1; i<nums.size(); i++){
            if(nums[i]==nums[i-1]){
                count++;
            }else{
                count=1;
            }
            maxm=max(maxm,count);
            if(maxm==count)ans=nums[i];
        }
        return ans;
    }
};