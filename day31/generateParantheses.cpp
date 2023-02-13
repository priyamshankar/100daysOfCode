class Solution {
public:
    void rec(vector<string> &ans, int n, int left, int right,string temp){
        if(left==n && right==n){
            ans.push_back(temp);
            return;
        }
        if(left>n || right >n)return;

        string temp1=temp;
        if(left>right){
            temp+=')';
            rec(ans,n,left,right+1,temp);
        }
        temp1+='(';
        rec(ans,n,left+1,right,temp1);

    }
    vector<string> generateParenthesis(int n) {
        if(n==0)return {};

        vector<string> ans;
        // ans.push_back('(');

        rec(ans,n,1,0,"(");
        return ans;
    }
};