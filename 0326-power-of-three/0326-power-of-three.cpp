class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0) return false;

        bool ans = func(n);

        return ans;

        
    }

    bool func(int n){

        if(n == 1) return true;

        if((n % 3) != 0) return false;

        return func(n / 3);
    }
};