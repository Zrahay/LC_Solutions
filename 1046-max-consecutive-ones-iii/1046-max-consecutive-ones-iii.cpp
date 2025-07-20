class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        int right = 0;
        int count_zeros = 0;
        int maxi = INT_MIN;

        while(right < n){
            if(nums[right] == 0) count_zeros++;

            while(count_zeros > k){
                if(nums[left] == 0){
                    count_zeros--;

                }

                left++;
            }

            if(count_zeros <= k){
                maxi = max(maxi, (right - left + 1));
            }
            right++;
        }

        return maxi;
    }
};