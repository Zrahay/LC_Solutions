class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n=nums.size();

        sort(nums.begin(), nums.end());

        int maxi=*max_element(nums.begin(), nums.end());
        int mini=*min_element(nums.begin(), nums.end());

        //Check when all the elements are equal
        

        if(k>maxi || mini<k) return -1;

        if(n==1 && k<nums[0]){
            return 1;
        }
         if(n==1 && nums[0]==k) return 0;

         //In case all the elements are the same, then
         

        set<int>myset;
        for(int i=n-2;i>=0;i--){
            if(nums[i]!=maxi){
                myset.insert(nums[i]);
            }
        }
        int count=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1])count++;
        }
        if(count==(nums.size()-1) && k==maxi) return 0;
        
        if(count==(nums.size()-1) && k<maxi) return 1;

        if(myset.size()==0) return 0;

        myset.insert(k);
        return myset.size();
    }
};