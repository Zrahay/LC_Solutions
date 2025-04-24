class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int,int>mpp;

        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;

        }

        int i=0;
        for(auto it:mpp){
            nums[i]=it.first;
            if(i==nums.size()-1) break;
            i++;
        
        }

        return mpp.size();
    }
};