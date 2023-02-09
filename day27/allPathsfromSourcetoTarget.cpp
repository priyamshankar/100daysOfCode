class Solution {
public:
    void dfs(vector<vector<int>>& graph,vector<vector<int>>& ans,vector<int>&temp, int node){
        temp.push_back(node);
        for(int i : graph[node]){
            if(i==graph.size()-1){
                temp.push_back(i);
                ans.push_back(temp);
                temp.pop_back();
                // temp.clear();
            }
            dfs(graph, ans,temp,i);
            temp.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>ans;
        vector<int>temp;
        dfs(graph,ans,temp,0);
        return ans;
    }
};