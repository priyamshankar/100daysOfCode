
//program link : https://leetcode.com/problems/permutation-in-string/?envType=study-plan&id=algorithm-i

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size()<s1.size())return false;
        if(s1==s2)return true;
        vector<int>farr(26,0);
        vector<int>sarr(26,0);
        int matchCase=0;
        int l=0;
        int r=0;
        while(r<s1.size()){
            farr[s1[r]-97]++;
            sarr[s2[r]-97]++;
            r++;
        }
        for(int i=0; i<26; i++){
            if(farr[i]==sarr[i])matchCase++;
        }
        cout<<matchCase;
        if(matchCase==26)return true;
        while(r<s2.size()){
            sarr[s2[l]-97]--;
            if(sarr[s2[l]-97]==farr[s2[l]-97]){
                matchCase++;
            }else if(sarr[s2[l]-97]==farr[s2[l]-97]-1){
                matchCase--;
                }

            sarr[s2[r]-97]++;
            if(sarr[s2[r]-97]==farr[s2[r]-97]){
                matchCase++;
            }else if(sarr[s2[r]-97] == farr[s2[r]-97]+1) {
                matchCase--;
                }
            if(matchCase==26)return true;

            l++;
            r++;
        cout<<matchCase;
        }
        return false;
    }
};