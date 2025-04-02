class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxi= *max_element(nums.begin(), nums.end());
        int low=1;
        int high=maxi;

        while(low<=high){
            int mid = (low)+(high-low)/2;
            int ans = cal(nums,mid);
            if(ans<=threshold) high=mid-1;

            else low=mid+1;
        }

        return low;
    }
    long long cal(vector<int>& nums, int n){
        long long len = nums.size();

        long long sum=0;
        for(int i=0;i<len;i++){
            sum += ceil((double)nums[i]/(double)n);
        }

        return sum;
    }
};