class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(s == "") return 0;
        map<char,int>mpp;
        int maxi = INT_MIN;
        int left = 0;
        int right = 0;
        int count = 0;
        while(right < n){
            if(mpp.find(s[right]) == mpp.end()){
                mpp[s[right]]++;
                maxi = max(maxi, (right - left + 1));
                right++;
            }
            while(mpp.find(s[right]) != mpp.end()){
                mpp.erase(s[left]);
                left++;
            }

        }



        return maxi;
    }
};