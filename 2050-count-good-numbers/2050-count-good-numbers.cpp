class Solution {
public:
long long MOD = 1e9 + 7;
    int countGoodNumbers(long long n) {

        long long div = n / 2;
        if (n % 2 == 0) {
            long long ans1 = myPow(5, div);
            long long ans2 = myPow(4, div);
            long long ans = 1;
            ans = (ans * ans1) % MOD;
            ans2 = ans2 % MOD;
            ans = ans % MOD;
            ans = (ans * ans2)%MOD;

            return ans;
        }

        long long ans1 = myPow(5, div + 1);
        long long ans2 = myPow(4, div);
        long long ans = 1;
        ans = (ans * ans1) % MOD;
        ans2 = ans2 % MOD;
        ans = ans % MOD;
        ans = (ans * ans2)%MOD;

        return ans;
    }

    long long myPow(long long x, long long n) {
        if (n == 0)
            return 1;

        if (x == 0)
            return 0;
        long long ans = 1.0;

        long long n_new = n;

        n_new = abs(n_new);

        while (n_new > 0) {
            if (n_new % 2 == 0) {
                x = (1LL* x * x)%MOD;
                n_new = n_new / 2;
            } else {
                ans = (1LL* ans * x)%MOD;
                n_new = n_new - 1;
            }
        }

        if (n < 0) {
            return (1.0 / ans);
        }

        return ans%MOD;
    }
};