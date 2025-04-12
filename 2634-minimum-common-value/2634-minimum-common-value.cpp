class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        int i = 0;
        int j = 0;
        while(i < n1 && j < n2){
            if (nums1[i] == nums2[j]){
                return nums1[i];
                break;
                i++;
                j++;
            }

            if(nums1[i] < nums2[j]){
                i++;
                if(i == n1) break;
            }

            if (nums2[j] < nums1[i]){
                j++;

                if(j == n2) break;
            }
        }

        return -1;
    }
};