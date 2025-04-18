class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        int n = s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
                st.push(s[i]);
            }
            else if(s[i]==')' || s[i]==']' || s[i]=='}'){
                if(st.empty()==true){
                    return false;
                }
               else if(st.top()=='(' && s[i]==')'){
                st.pop();
               }
               else if(st.top()=='[' && s[i]==']'){
                st.pop();
               }
               else if(st.top()=='{' && s[i]=='}'){
                st.pop();
               }
               else{
                return false;
               }
            }
        }

        if(st.empty()==false) return false;

        return true;
    }
};