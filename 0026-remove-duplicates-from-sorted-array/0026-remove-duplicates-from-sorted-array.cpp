class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j=1;

        int count=0;
        int val = nums[0];
        for(int k=1;k<nums.size();k++){
            if(val!=nums[k]){
                nums[j]=nums[k];
                j++;
                val=nums[k];
                count++;
            }
        }

        return count+1;
    }
};