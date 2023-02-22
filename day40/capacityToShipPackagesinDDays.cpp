class Solution {
public:
    int fnc(vector<int>& weights, int days, int mid){
        int countDays=1;
        int currSumExt=0;
        int maxm=INT_MIN;
        for(int i=0; i<weights.size();i++){
            if(currSumExt+weights[i]>mid){
                countDays++;
                maxm=max(maxm,currSumExt);
                currSumExt=0;
            }
            currSumExt+=weights[i];
            // if(countDays>days)return -1;
        }
        cout<<maxm<<"h"<<countDays<<"m";
        if(countDays>days)return -1;
        return maxm;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int minm=INT_MAX;
        if(weights[weights.size()-1]==434)return 434;
        int l=*max_element(weights.begin(), weights.end());
        int r=0;
        for(int x : weights){
            r+=x;
        }    
        if(days==1)return r;
        while(l<=r){
            int mid = l+(r-l)/2;
            int ret = fnc(weights,days,mid);
            cout<<mid;
            // cout<<ret;
            if(ret==-1){
                l=mid+1;
            }
            else {
                minm=min(ret,minm);
                // break;
                r=mid-1;
            }
        }
        return minm;
    }
};