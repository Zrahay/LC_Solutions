class Solution {
public:
    int maxScore(string s) {
        // Pre compute the number of ones
        int ones = 0;
        vector<int> prefix_sum(s.length(),0);

        if(s[0] == '1'){
            prefix_sum[0] = 1;
        }
        for(int i =1 ; i < s.length(); i++){
            ones = 0;
            if(s[i] == '1'){
                ones++;
               
            }
             prefix_sum[i] = ones + prefix_sum[i-1];
        }

        // Count the number of zeros at each step and see the number of ones at that step as well.
        int new_sum = accumulate(prefix_sum.begin(), prefix_sum.end(), 0);

        if(new_sum == 0){
            return (s.length()/2);
        }
        int zeros = 0;
        int sum = INT_MIN;
        for(int i = 0; i < s.length() - 1; i++){
            if (s[i] == '0'){
                zeros++;
            }

            int ans = zeros + prefix_sum[s.length()-1] - prefix_sum[i];
            sum = max(sum, ans);
        }

        return sum;
    }
};