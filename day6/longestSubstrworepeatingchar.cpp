class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>hTable;
        int maxmCount=0;
        int l=0; int j=0;
        while(j<s.size() && l<s.size()){
            auto itr = hTable.find(s[j]);
            if(itr==hTable.end()){
                hTable.insert(s[j]);
                maxmCount=max(maxmCount,j-l+1);
                j++;
            }else{
                hTable.erase(s[l]);
                l++;
            }
        }
        return maxmCount;
    }
};