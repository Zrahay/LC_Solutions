class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix_sum(n);

        int index = -1;
        prefix_sum[0] = nums[0];
        for(int i = 1; i < n; i++){
            prefix_sum[i] = prefix_sum[i - 1] + nums[i];
        }

        int left_sum = 0;
        int right_sum = prefix_sum[n-1] - nums[0];
        if(left_sum == right_sum) return 0;

        for(int i = 1; i < n-1; i++){
            left_sum += nums[i - 1];
            right_sum = prefix_sum[n - 1] - prefix_sum[i];
            if(left_sum == right_sum) return i;
        }

        right_sum = 0;
        left_sum = prefix_sum[n - 1] - nums[n - 1];

        if(left_sum == right_sum) return n-1;

        return -1;

    }
};