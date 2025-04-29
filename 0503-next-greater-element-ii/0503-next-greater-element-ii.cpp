class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int>st;

        vector<int>nge(n);

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums[i]){
                st.pop();
            }

            if(st.empty()==true){
                nge[i] = INT_MIN;
            }

            else{
                nge[i] = st.top();
            }

            if(nge[i]==INT_MIN){
                int ans = check(nums,i);
                nge[i]=ans;
            }

            st.push(nums[i]);
        }

        for(int i=0;i<n;i++){
            if(nge[i]==INT_MIN){
                nge[i]=-1;
            }
        }

        return nge;
    }

    int check(vector<int>&v, int val){
        int n = v.size();
        for(int i=0;i<n;i++){
            if(v[i]>v[val]){
                return v[i];
            }
        }
        return -1;
    }
};