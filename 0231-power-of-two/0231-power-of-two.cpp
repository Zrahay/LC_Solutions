class Solution {
public:
    bool isPowerOfTwo(int n) {
        if( n < 0 || n == 0) return false;

        bool ans = func(n);

        return ans;
    }

    bool func(int n){

        if(n == 1) return true;

        if((n % 2) != 0) return false;

        return func(n / 2);
    }
};