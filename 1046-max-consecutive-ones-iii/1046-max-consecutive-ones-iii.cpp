class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0;
        int r = 0;
        int maxlen = 0;
        int k2 = k;

        while(r < n){
            if(nums[r] == 1){
                maxlen = max(maxlen, r-l+1);
            }

            else if(nums[r] == 0 && k != 0){
                maxlen = max(maxlen, r-l+1);
                --k;
            }
            else if(k == 0){
                k = k2;
                l = l + 1;
                r = l;
                continue;
            }
           r++;
        }

        return maxlen;
    }
};