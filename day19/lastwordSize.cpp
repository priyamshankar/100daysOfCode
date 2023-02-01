class Solution {
public:
    int lengthOfLastWord(string s) {
        int sz=s.size()-1;
        bool st=false;
        int count=0;
        for(int i=sz; i>=0; i--){
            if(s[i]==' ' && st==false){
                continue;
            }else st=true;
            if(s[i]==' ' && st==true){
                break;
            }
            else count++;
        }
        return count;
    }
};