class Solution {
public:
    int pivotInteger(int n) {
        vector<int> num(n);
        for (int i = 1; i <= n; i++) {
            num[i - 1] = i;
        }

        if(n == 1) return 1;

        // We need to calculate the prefix of the array

        vector<int> prefix_sum(n);
        prefix_sum[0] = num[0];

        for (int i = 1; i < n; i++) {
            prefix_sum[i] = prefix_sum[i - 1] + num[i];
        }

        // Now we need to calculate the sum at a particular index and the sum
        // from that index to the end
        int index = -1;
        for (int i = 0; i < n; i++) {
            int sum = prefix_sum[i];
            int sum1 = prefix_sum[n - 1] - prefix_sum[i] + num[i];
            if (sum == sum1) {
                index = i+1;
            }
        }

        return index;
    }
};