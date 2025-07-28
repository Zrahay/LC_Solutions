class Solution {
public:
    long long numOfSubsequences(string s) {
        int n = s.size();
        vector<int>prefix(n ,0);
        vector<int>suffix(n, 0);

        if(s[0] == 'L'){
            prefix[0] = 1;
        }
        if(s[n - 1] == 'T'){
            suffix[n - 1] = 1;
        }
        for(int i = 1; i < n; i++){
            if(s[i] == 'L'){
                prefix[i] = prefix[i - 1] + 1;
            }
            else prefix[i] = prefix[i - 1];
        }


        for(int i = n - 2; i >= 0; i--){
            if(s[i] == 'T'){
                suffix[i] = suffix[i + 1] + 1;
            }
            else suffix[i] = suffix[i + 1];
        }


        long long one = 0;
        long long two = 0;
        long long three = 0;
        long long best = 0;


        // Start the one final iteration
        for(int i = 0; i < n; i++){
            long long p = (i > 0)? prefix[i -1]:0;
            long long sf = (i < n - 1)?suffix[i + 1]:0;

            if(s[i] == 'C') one += p*sf;
            if(s[i] == 'C') two += ((p+1) * sf);
            if(s[i] == 'C') three += (p * (sf + 1));
            p = prefix[i];
            best = max(best,sf*p);


        }

        return max({two, three, (one + best)});


    }
};