class Solution {
public:
    int mySqrt(int x) {
        int low = 0;
        int high = x;
        int maxi = INT_MIN;
        
        while(low <= high){
            int mid = (low) + (high - low)/2;
            long long prod = 1;
            prod = prod * mid;
            prod = prod * mid;
            if (prod == x) return mid;

            else if (prod < x){
                maxi = max (mid, maxi);
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return maxi;
    }
};