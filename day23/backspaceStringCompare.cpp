//https://leetcode.com/problems/backspace-string-compare/description/?envType=study-plan&id=algorithm-ii

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<int>st1;
        stack<int>st2;
        for(int i=0; i<s.size(); i++){
            if(s[i]!='#'){
                st1.push(s[i]);
            }else{
                if(!st1.empty())
                    st1.pop();
            }
        }
        for(int i=0; i<t.size(); i++){
            if(t[i]!='#'){
                st2.push(t[i]);
            }else{
                if(!st2.empty())
                    st2.pop();
            }
        }
        while(!st1.empty() && !st2.empty()){
            if(st1.top()!=st2.top()){
                return false;
            }
            st1.pop(); st2.pop();
        }
        if(!st1.empty() || !st2.empty()){
            return false;
        }
        return true;
    }
};