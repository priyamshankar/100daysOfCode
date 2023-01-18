
//problem link : https://leetcode.com/problems/reverse-words-in-a-string-iii/?envType=study-plan&id=algorithm-i
class Solution {
public:
    string reverseWords(string s) {
        int l=0;
        int r=0;
        for(int i=0 ; i<s.size(); i++){
            if(s[i]==' ' || i==s.size()-1){
                r=i-1;
                if(i==s.size()-1)r=i;
                while(r>=l){
                    swap(s[r],s[l]);
                    r--;
                    l++;
                }
                l=i+1;
            }
        }
        return s;
    }
};