class Solution {
public:

    bool anagramCheck(vector<int>&pan,vector<int>&san){
        for(int i=0; i<26;i++){
            if(pan[i]!=san[i]){
                return false;
            }
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        if(p.size()>s.size())return {};
        vector<int>pan(26,0);
        vector<int>san(26,0);
        vector<int>res;
        for(int i=0; i<p.size(); i++){
            char c = p[i];
            pan[c-'a']++;
        }
        for(int i=0; i<p.size();i++){
            char c=s[i];
            san[c-'a']++;
        }
        int l=0;
        if(anagramCheck(pan,san))res.push_back(0);
        for(int i=p.size(); i<s.size(); i++){
            char c= s[i];
            san[c-'a']++;
            c=s[l];
            san[c-'a']--;
            l++;
            if(anagramCheck(pan,san))res.push_back(l);
            else cout<<i;

        }
        return res;
    }
};