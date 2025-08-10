class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int count = 0;

        // Count the freq of each digit in digits
        map<int,int>mpp;

        for(int i = 0; i < digits.size(); i++){
            mpp[digits[i]]++;
        }

        for(int i = 1; i <= 9; i++){
            if(mpp[i] == 0) continue;
            mpp[i]--;
            for(int j = 0; j <= 9; j++){
                if(mpp[j] == 0) continue;
                mpp[j]--;

                for(int k = 0; k <= 8; k = k + 2){
                    if(mpp[k] == 0) continue;
                    mpp[k]--;
                    count++;
                    mpp[k]++;
                }
                mpp[j]++;
            }
            mpp[i]++;
        }

        return count;
    }
};