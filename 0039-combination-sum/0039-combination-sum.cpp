class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>>ans1;
        vector<int>ans;

        int ind = 0;
        recur(ind, ans1, ans, target, candidates, n);

        return ans1;
    }

    void recur(int ind, vector<vector<int>>& ans1, vector<int>& ans, int target, vector<int>& candidates, int n){
        if(ind == n){
            if(target == 0){
                ans1.push_back(ans);
            }
            return;
        }

        if(candidates[ind] <= target){
            ans.push_back(candidates[ind]);
            recur(ind, ans1, ans, target - candidates[ind], candidates, n);
            ans.pop_back();
        }
        recur(ind + 1, ans1, ans, target, candidates, n);

        return;
    }
};