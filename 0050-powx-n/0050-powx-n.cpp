class Solution {
public:
    double myPow(double x, int n) {

        long long N = n;
        if(n < 0){
            N = -1 * (N);
            x = 1 / x;
        }

        double ans = 1;

        while(N > 0){
            if(N  % 2 != 0){
                ans = ans*(x);
                N--;
            }
            x = x * x;
            N = N / 2;
        }

        return ans;
    }
};