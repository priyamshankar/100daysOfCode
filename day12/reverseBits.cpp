class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans=0;
        for(int i=0; i<32; i++){
            if(n&1){
                // ans=ans|n;
                ans=1|ans;
            }
            else ans=ans|0;
            n=n>>1;
            if(i==31)break;
            ans=ans<<1;
        }
        return ans;
    }
};