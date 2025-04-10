class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();

        int n=n1+n2;
        int target1 = (n)/2;
        int target2 = (n/2)-1;

        int store=0;
        int i=0;
        int j=0;

        int el1=-1;
        int el2=-1;

        while(i<n1 && j<n2){
            if(nums1[i]<nums2[j]){
                if(store==target1) el1 = nums1[i];
                else if(store==target2) el2 = nums1[i];
                i++;
                store++;

            }
            else{
                if(store==target1) el1 = nums2[j];
                else if(store==target2) el2 = nums2[j];
                store++;
                j++;
            }
        }

        while(i<n1){
            if(store==target1) el1 = nums1[i];
            else if(store==target2) el2= nums1[i];
            store++;
            i++;
        }

        while(j<n2){
            if(store==target1) el1 = nums2[j];
            else if(store==target2) el2 = nums2[j];
            store++;
            j++;
        }

        if(n%2==0){
            double ans = (double)(el1)+(double)(el2);
            return (ans)/(2.0);
        }

        else{
            return el1;
        }


    }
};