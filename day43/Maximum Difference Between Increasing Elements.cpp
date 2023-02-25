class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int minm=nums[0];
        int maxm=0;
        for(int x : nums){
            minm=min(minm,x);
            int temp=x-minm;
            maxm=max(temp,maxm);
        }
        if(maxm<=0)return -1;
        return maxm;
    }
};