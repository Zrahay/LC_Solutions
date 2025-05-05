class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        map<int,int>mpp;
        int maxi = 0;
        long long sum = 0;

        for(int  i = 0; i < n ;i++){
            if(nums[i] == 1){
                sum += 1;
            }
            else{
                sum = sum - 1;
            }

            if(sum == 0){
                maxi = max(maxi,(i+1));
            }

            if(mpp.find(sum) == mpp.end()){
                mpp[sum] = i;
            }
            else{
                int index = mpp[sum];

                maxi = max(maxi, (i-index));
            }
        }

        return maxi;
    }
};