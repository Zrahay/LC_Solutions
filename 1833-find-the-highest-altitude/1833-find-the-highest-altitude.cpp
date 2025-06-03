class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        int maxi = INT_MIN;

        vector<int> prefix(n);

        prefix[0] = gain[0];
        maxi = max(maxi, prefix[0]);

        for(int i = 1; i < n; i++){
            prefix[i] = prefix[i - 1] + gain[i];
            maxi = max(maxi, prefix[i]);
        }

        if(maxi < 0) return 0;
        return maxi;
    }
};