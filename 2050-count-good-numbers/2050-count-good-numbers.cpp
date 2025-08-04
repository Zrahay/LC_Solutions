class Solution {
public:
    int mod=1e9+7;

    int mod_pow(int base, long long int exponent) {
        int result = 1;
        //base %= mod;  // handle base larger than mod
        while (exponent > 0) {
            if (exponent & 1)  // if lowest bit is 1
                result = (1LL * result * base) % mod;
            base = (1LL * base * base) % mod;  // square the base
            exponent >>= 1;  // shift exponent right (divide by 2)
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        long long int odd=0,eve=0;
        if(n%2==0){
            odd=eve=n/2;
        }else{
            odd=n/2;
            eve=n/2+1;
        }

        int combo=(1LL*(mod_pow(5,eve))*(mod_pow(4,odd)))%mod;
        return combo;
    }
};