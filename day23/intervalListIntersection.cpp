class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>>ans;
        int fptr=0;
        int sptr=0;
        vector<int>temp(2);
        while(fptr<firstList.size() && sptr<secondList.size()){
            if(firstList[fptr][0]<=secondList[sptr][1] && firstList[fptr][1]>=secondList[sptr][0])  {
                // vector<int>temp;
                temp[0]=(max(firstList[fptr][0],secondList[sptr][0]));
                temp[1]=(min(firstList[fptr][1],secondList[sptr][1]));
                ans.push_back(temp);
            }
                // fptr++;sptr++;
            if(firstList[fptr][1]<secondList[sptr][1]){
                fptr++;
                // sptr++;
            }else {
                sptr++;
                // fptr++;
            }
        }
        
        return ans;
    }
};