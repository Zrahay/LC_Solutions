class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;

        if(x == 0) return 0;
        double ans = 1.0;

        long long n_new = n;

        n_new = abs(n_new);



        while(n_new > 0){
            if(n_new % 2 == 0){
                x = x * x;
                n_new = n_new / 2;
            }
            else{
                ans = ans * x;
                n_new = n_new - 1;
            }
        }


        if(n < 0){
            return (1.0 / ans);
        }

        return ans;



        return ans;


    }
};