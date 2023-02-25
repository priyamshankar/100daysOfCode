class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minm=INT_MAX;
        int maxm=0;
        for(int x : prices){
            minm=min(minm,x);
            int temp=x-minm;
            maxm=max(temp,maxm);
        }
        if(maxm<0)return 0;
        return maxm;
    }
};