class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefix_sum(n);

        prefix_sum[0] = nums[0];
        for(int i = 1; i < n; i++){
            prefix_sum[i] = prefix_sum[i-1] + nums[i];
        }

        int index = -1;
        int left_sum = 0;
        int right_sum = prefix_sum[n - 1];

        int temp = right_sum - prefix_sum[0];
        if(left_sum == temp){
            index = 0;
            return index;
        }

        for(int i = 1;i < n - 1; i++){
            left_sum = left_sum + nums[i - 1];
            int temp = right_sum - prefix_sum[i];

            if(left_sum == temp){
                index = i;
                cout<<"Output is here"<<"\n";
                return index;
            }
        }

        right_sum = 0;
        left_sum = left_sum + nums[n - 2];
        if(left_sum ==  right_sum){
            index = n - 1;
            return index;
        }

        return -1;
    }
};