class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        set<int>st;

        for(int i = 0; i < n1; i++){
            for(int j = 0; j < n2; j++){
                if(nums1[i] == nums2[j]){
                    st.insert(nums1[i]);
                }
            }
        }

        vector<int>ans(st.begin(), st.end());

        return ans;
    }
};