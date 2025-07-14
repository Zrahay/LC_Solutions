class Solution {
public:
    bool isPalindrome(string s) {
        // To make upper letters lower (This function just works correctly)
        for(int i = 0; i < s.size(); i++){
            if(((s[i] >= 65 && s[i] <= 90))){
                s[i] = tolower(s[i]);
                
            }
        }



        

        int i = 0;

        int j = s.size() - 1;

        while(i <= j){
            if(isalnum(s[i]) == false){
                i++;
                continue;
            }

            else if(isalnum(s[j]) == false){
                j--;
                continue;
            }

            else if(s[i] != s[j]){
                return false;
            }
            else{
                i++;
                j--;
            }
        }

        return true;
    }
};