class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<int>collect;
        int i = 0;
        int sum = 0;
        

        vector<vector<int>> ans;
        
        
        
        helper(ans, candidates, collect, n, i, target);



        return ans;
    }

    void helper(vector<vector<int>>& ans, vector<int>& candidates, vector<int>& collect, int n, int i, int target){
        
        if(target == 0){
            ans.push_back(collect);
            return;
        }

        if((i == n) || (target < 0)) return;


        collect.push_back(candidates[i]);
        helper(ans, candidates, collect, n, i, target - candidates[i]);

        collect.pop_back();

        helper(ans, candidates, collect, n, i + 1, target);

        return;


        
    }
};