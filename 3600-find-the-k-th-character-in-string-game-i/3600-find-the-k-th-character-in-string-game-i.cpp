class Solution {
public:
    char kthCharacter(int k) {
        string str = "ab";
        char ans = recur(k, str);
        return ans;
    }

    char recur(int k, string str){

        if(str.size() >= k){
            return str[k - 1];
        }

        int n = str.size();

        for(int i = 0; i < n; i++){
            if(str[i] == 'z'){
                str = str + 'a';
            }
            else str = str + char(str[i] + 1);
        }

        return recur(k, str);
    }
};