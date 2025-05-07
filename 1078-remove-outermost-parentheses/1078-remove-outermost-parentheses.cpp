class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char>st;
        string ans = "";

        for(int i = 0 ; i < s.length(); i++){
            if(s[i] == '('){
                if(st.empty()){
                    st.push(s[i]);
                }
                else{
                    st.push(s[i]);
                    ans = ans + s[i];
                }
            }

            else if (s[i] == ')'){
                
                st.pop();
                if(st.empty()){
                    continue;
                }
                else{
                    ans = ans + s[i];
                }
                
            }
        }

        return ans;
    }
};