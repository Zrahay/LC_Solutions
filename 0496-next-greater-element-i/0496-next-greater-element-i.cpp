class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();

        vector<int>v(n1,-1);
        int index=500;

        for(int i=0;i<n1;i++){
            int temp = nums1[i];
            int index=INT_MAX;
            for(int j=0;j<n2;j++){
                if(temp==nums2[j]) index=j;

                else if(j>index){
                    if(nums2[j]>nums2[index]){
                        v[i]=nums2[j];
                        break;
                    }
                }
            }
        }

        return v;
    }
};