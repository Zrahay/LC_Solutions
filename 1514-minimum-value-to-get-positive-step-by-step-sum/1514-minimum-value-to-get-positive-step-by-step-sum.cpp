class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int low = 1;
        int high = 1e9;
        int n = nums.size();
        int val = -1;

        if(n == 1){
            return abs(nums[0])+1;
        }

        while(low <= high){
            int mid = (low) + (high - low)/2;
            bool ans = check(nums, n, mid);
            if(ans == true){
                val = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return val;
    }
    bool check(vector<int>&v, int n, int mid){
        vector<int> prefix_sum(n);
        prefix_sum[0] = mid + v[0];
        if(prefix_sum[0] < 1) return false;
        for(int i = 1; i < n; i++){
            prefix_sum[i] = prefix_sum[i - 1] + v[i];
            if(prefix_sum[i] < 1) return false;
        }
        return true;
    }
};