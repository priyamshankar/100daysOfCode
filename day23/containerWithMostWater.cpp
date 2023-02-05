class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0; int r=height.size()-1;
        int length=r;
        int maxm=INT_MIN;
        int temp;
        while(l<=r){
            temp=length*(min(height[l],height[r]));
            // temp*=length;
            cout<<temp;
            maxm=max(maxm,temp);
            if(height[l]<height[r]){
                l++;
            }else r--;
            length--;
        }
        return maxm;
    }
};