class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();

        int sum_global = 0;

        for(int i = 0; i < n; i++){
            int sum_local = 0;
            for(int j = i; j < n; j++){
                sum_local += arr[j];
                if((j+i) % 2 == 0){
                    sum_global+= sum_local;
                }
            }
        }

        return sum_global;
    }
};