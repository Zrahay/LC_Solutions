class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> ans;

        int ind = 0;
        vector<int>v;

        ans = recursion(n, ind, ans, v, nums);

        return ans;
    }

    vector<vector<int>> recursion(int n, int ind, vector<vector<int>> &ans, vector<int>& v, vector<int>& nums){
        if(ind >= n){
            ans.push_back(v);
            return ans;
        }

        // Add the new elements;
        v.push_back(nums[ind]);
        ind++;
        recursion(n,ind, ans, v, nums);

        // Remove that element
        v.pop_back();
        recursion(n, ind, ans, v, nums);

        return ans;
    }
};