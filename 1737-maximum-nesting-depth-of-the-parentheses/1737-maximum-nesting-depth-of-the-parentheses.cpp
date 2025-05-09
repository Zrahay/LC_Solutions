class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();

        int sum = 0;
        int maxlen = 0;
        for(int i = 0; i < n ; i++){
            if(s[i] == '('){
                sum++;
                maxlen = max(maxlen, sum);
            }
            else if(s[i] == ')') sum--;
        }

        return maxlen;
    }
};