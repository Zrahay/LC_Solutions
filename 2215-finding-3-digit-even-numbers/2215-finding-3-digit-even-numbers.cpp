class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();

        map<int,int>mpp1;

        for(int i = 0; i < n; i++){
            mpp1[digits[i]]++;
        }

        map<int,int>copy = mpp1;
        vector<int>v;

        // [<2,1>,<1,1>,<3,1>,<0,1>]
        // Run a loop from 100 to 199

        for(int i = 100; i < 999; i = i + 2){
            mpp1 = copy;
            string temp = to_string(i); // "100"
            int temp_size = temp.size();
            int count = 0;

            for(int j = 0 ; j < temp_size; j++){
                
                int val = temp[j] - '0';
                if(mpp1.find(val) != mpp1.end()){

                    if(mpp1[val] == 0){
                        mpp1.erase(val);
                    }
                    else{
                        mpp1[val]--;
                    count++;
                    }

                    if(count == 3){
                        v.push_back(i);
                    }
                    
                }
            }

        }

        return v;

    }
};