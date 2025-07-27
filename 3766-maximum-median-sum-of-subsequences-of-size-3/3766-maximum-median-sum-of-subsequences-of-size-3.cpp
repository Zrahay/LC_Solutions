class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        sort(nums.begin(), nums.end());


        for(int  i = n/3; i < n; i= i + 2){
            sum += nums[i];
        }

        return sum;
    }
};