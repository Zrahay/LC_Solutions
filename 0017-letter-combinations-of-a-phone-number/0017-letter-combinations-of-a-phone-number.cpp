class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int n = digits.size();

        vector<string> ans;

        if (digits == "")
            return ans;
        int i = 0;
        int j = 0;

        unordered_map<char, string> mpp = {
            {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
        string str = "";

        ans = recur(mpp, digits, i, ans, n, str);

        return ans;
    }

    vector<string> recur(unordered_map<char, string> mpp, string digits, int i, vector<string>& ans, int n, string str) {

        if (str.size() >= n) {
            ans.push_back(str);
            return ans;
        }

        for (int k = 0; k < mpp[digits[i]].size(); k++) {
            str = str + mpp[digits[i]][k];
            
            recur(mpp, digits, i + 1, ans, n, str);
            str.pop_back();
        }

        return ans;
    }
};