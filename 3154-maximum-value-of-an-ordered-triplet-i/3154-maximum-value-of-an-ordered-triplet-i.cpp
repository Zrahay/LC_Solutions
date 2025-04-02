class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();
        if(n==3){
            long long val = (nums[0]-nums[1]);
            val *= nums[2];
            if(val<0) return 0;
            else return val;
        }
        if(n<3) return 0;

        long long val=INT_MIN;
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                for(int k=j+1;k<n;k++){
                    val = max(val, 1LL*(nums[i]-nums[j])*(nums[k]));
                }
            }
        }

        if(val<0) return 0;
        else return val;
    }
};