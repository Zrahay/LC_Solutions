class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        // If the highest freq is 1, output the highest number corresponding to it

        int maxi = INT_MIN;

        map<int,int>mpp;

        for(int i = 0; i < nums.size(); i++){
            mpp[nums[i]]++;
        }

        // Now we have the map with us. We need to check for the highest freq now

        auto it = mpp.begin();

        while(it != mpp.end()){
            if(it->second > maxi){
                maxi = it->second;
            }

            it++;
        }

        // Now we need to check ki which elements have the same frequency

        it = mpp.begin();

        int high = 0;

        while(it != mpp.end()){
            if(it->second == maxi) high += maxi;

            it++;
        }
        return high;
    }
};