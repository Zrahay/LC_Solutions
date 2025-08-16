class Solution {
public:
    vector<string> generateParenthesis(int n) {
        int open = n;
        int close = n;

        vector<string>ans1 = {"()"};

        if(n == 1){
            return ans1;
        }

        vector<string>ans;
        string str = "";

        recur(open, close, ans, str, n);

        return ans;
    }

    vector<string> recur(int open, int close, vector<string>& ans, string &str, int n){
        if(str.size() == (2*n)){
            ans.push_back(str);
            return ans;
        }

        if(open > 0){
            str.push_back('(');
            recur(open - 1, close, ans ,str , n);
            str.pop_back();
        }

        if(close > 0 && (open < close)){
            str.push_back(')');
            recur(open, close - 1, ans, str, n);
            str.pop_back();
        }

        return ans;
    }
};