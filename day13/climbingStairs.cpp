//question Link : https://leetcode.com/problems/climbing-stairs/description/?envType=study-plan&id=algorithm-i
class Solution {
public:
    int recDp(int n,vector<int>&arr){
        if (n<=1)return arr[n]=1;

        if(arr[n]!=-1){
            return arr[n];
        }
        arr[n]=recDp(n-1,arr)+recDp(n-2,arr);
        return arr[n];
    }
    int climbStairs(int n) {
        vector<int>arr(n+1,-1);
        recDp(n,arr);
        return arr[n];
    }
};