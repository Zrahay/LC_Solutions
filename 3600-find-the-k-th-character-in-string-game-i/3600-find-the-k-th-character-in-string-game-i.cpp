class Solution {
public:
    char kthCharacter(int k) {
        string str = "ab";

        while(true){
            if(str.size() >= k){
                return str[k - 1];
                break;
            }

            str = str + recur(str);

        }
    }

    string recur(string str){
        string ans = "";

        for(int i = 0; i < str.size(); i++){
            if(str[i] == 'z'){
                ans = ans + 'a';
            }
            ans = ans + char(str[i] + 1);
        }

        return ans;
    }
};