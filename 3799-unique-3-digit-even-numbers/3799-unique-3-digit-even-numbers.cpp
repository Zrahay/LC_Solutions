class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        set<int>st;

        for(int i = 0; i < digits.size(); i++){
            if(digits[i] == 0) continue;
            for(int j = 0; j < digits.size(); j++){
                if(i == j) continue;
                for(int k = 0; k < digits.size(); k++){
                    if(k == i || k == j)continue;

                    int num = (digits[i] * 100) + (digits[j] * 10) + digits[k] * 1;
                    if(num % 2 == 0){
                        st.insert(num);
                    }
                }
            }
        }

        return st.size();
    }
};