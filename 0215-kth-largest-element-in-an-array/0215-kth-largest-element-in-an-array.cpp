class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Pehle sort karte hai in descending and phir return k-1th term

        sort(nums.begin(), nums.end(), greater<int>());

        return nums[k-1];
    }
};