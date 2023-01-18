//problem link : https://leetcode.com/problems/reverse-string/?envType=study-plan&id=algorithm-i

class Solution {
public:
    void reverseString(vector<char>& s) {
        int l=0;
        int r=s.size()-1;
        while(l<r){
            swap(s[l],s[r]);
            l++;r--;
        }
    }
};