class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mpp1;
        unordered_map<char,bool> mpp2;

        for(int i = 0; i < s.length(); i++){
            if(mpp1.find(s[i]) != mpp1.end()){
                if(mpp1[s[i]] != t[i]) return false;
            }

            else{
                if(mpp2[t[i]]==true) return false;

                mpp1[s[i]] = t[i];
                mpp2[t[i]] = true;
            }
        }

        return true;
    }
};