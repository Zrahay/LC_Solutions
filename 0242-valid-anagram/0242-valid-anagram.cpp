class Solution {
public:
    bool isAnagram(string s, string t) {
        // We can simply use two maps to check the feasibility and see if the solution is even possible or not?

        map<char,int>mpp1;

        map<char,int>mpp2;

        //Map 1 ke liye
        for(int i = 0; i < s.length(); i++){
            mpp1[s[i]]++;
        }

        // Second string ke liye
        for(int i = 0; i < t.length(); i++){
            mpp2[t[i]]++;
        }

        if(s.length() != t.length()) return false;

        int max_len = max(s.length(), t.length());

        // Ab mpp2[s[i]] == mpp1[s[i]] laga ke karenge
        for(int i = 0; i < max_len ;i++){

            if(mpp2[s[i]] != mpp1[s[i]]) return false;
        }
 
        

        return true;


    }
};