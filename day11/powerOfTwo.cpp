class Solution {
public:
    bool isPowerOfTwo(int n) {
        // int a=4,b=3;
        // int c=a&b;
        if(n==INT_MIN){
            return false;
        }
        if(n==0)return false;
       if((n&(n-1))==0){
           return true;
       }
        return false;
    }
};