//problem link:  https://leetcode.com/problems/first-bad-version/?envType=study-plan&id=algorithm-i


// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {

        int l=1; int r=n;
        int count =0;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(isBadVersion(mid)){
                count=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return count;
    }
};