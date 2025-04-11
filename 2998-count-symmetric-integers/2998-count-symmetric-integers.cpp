class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for (int i = low; i <= high; i++) {
            string s = to_string(i);
            int n = s.length();

            if (n % 2 == 1)
                continue;

            int sum_1 = 0;
            for (int j = 0; j < (n / 2); j++) {
                int digit = s[j] - '0';
                sum_1 += digit;
            }

            int sum_2 = 0;
            for (int j = (n / 2); j < n; j++) {
                int digit = s[j] - '0';
                sum_2 += digit;
            }

            if (sum_1 == sum_2) {
                count++;
            }
        }

        return count;
    }
};