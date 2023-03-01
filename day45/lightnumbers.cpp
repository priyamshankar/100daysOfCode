class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> st;
        if(n<=0)return false;
        int temp=0; int loopN=n;
        // cout<<loopN%10 * loopN%10;
        while(loopN!=1){
            while(loopN!=0){
                int sq=loopN%10;
                temp+=(sq * sq);
                loopN/=10;
                cout<<temp<<endl;
            }
            // cout<<temp<<endl;
            if(temp==1){
                return true;
            }
            if(st.find(temp)==st.end()){
                st.insert(temp);
            }else {
                return false;
            }
            
            loopN=temp;
            temp=0;
        }
        return true;
    }
};

// class Solution {
// private:
//     int nextNumber(int n){
//         int newNumber = 0;
//         while(n!=0){
//             int num = n%10;
//             newNumber += num*num;
//             n = n/10;
//         }
//         return newNumber;
//     }
// public:
//     bool isHappy(int n) {
//         unordered_set<int> set;
//         while(n!=1 && !set.count(n)){
//             set.insert(n);
//             n = nextNumber(n);
//         }
//         return n==1;
//     }
// };