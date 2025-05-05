class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left = 0;
        
        long long prod = 1;
        int count = 0;

        int val = *min_element(nums.begin(), nums.end());
        if(val>=k) return 0;
        for(int right = 0; right < nums.size() ;right++){
            prod = prod * nums[right];
            while(prod >= k){
                prod = prod / nums[left];
                left++;
            }
            count = count + (right - left + 1);
        }

        return count;
    }
};