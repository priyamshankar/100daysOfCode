class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>>v;
        for(int i=0;i<nums2.size();i++){
            v.push_back({nums2[i],i});
        }
        sort(v.rbegin(),v.rend());
        long long sum=0;
        long long maxm=0;

        priority_queue<int,vector<int>,greater<int>>pt;
        
        for(int i=0;i<v.size();i++){
            auto &[a,b]=v[i];
            sum+=nums1[b];
            pt.push(nums1[b]);
            if(pt.size()==k)maxm=max(maxm,sum*a); 
            if(pt.size()>k-1){
                sum-=pt.top();
                pt.pop();
            }
        }
        return maxm;
    }
};