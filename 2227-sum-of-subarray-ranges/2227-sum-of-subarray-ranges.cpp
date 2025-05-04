class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long sum_min = 0;
        vector<int> nse_index = nse(nums);
        vector<int>pse_index = pse(nums);

        for(int i = 0;i<n;i++){
            int res1 = i - pse_index[i];
            int res2 = nse_index[i] - i;
            sum_min= (sum_min + (1LL*nums[i]*res1*res2));
        }
        
        
        vector<int>nge_index = nge(nums);
        vector<int>pge_index = pge(nums);

        long long sum_max = 0;
        for(int i= 0;i<n;i++){
            int res3 = i - pge_index[i];
            int res4 = nge_index[i] - i;
            sum_max = (sum_max+ (1LL*nums[i]*res3*res4));
        }

        long long ans = sum_max - sum_min;

        return ans;

    }
    vector<int> nse(vector<int>&v){
        int n = v.size();
        stack<int>st;
        vector<int> next(n);

        for(int i=v.size()-1;i>=0;i--){
            while(!st.empty() && v[st.top()]>=v[i]){
                st.pop();
            }

            if(st.empty()){
                next[i] = n;
            }
            else{
                next[i] = st.top();
            }

            st.push(i);
        }
        return next;
    }

    vector<int> pse(vector<int>&v){
        int n = v.size();
        stack<int>st;

        vector<int>prev(n);
        for(int i =0;i<n;i++){
            while(!st.empty() && v[st.top()]>v[i]){
                st.pop();
            }

            if(st.empty()){
                prev[i] = -1;
            }
            else{
                 prev[i] = st.top();
            }
            st.push(i);
           
        }
        return prev;

    }

    vector<int> pge(vector<int>& v){
        int n = v.size();
        stack<int>st;

        vector<int>prev(n);
        for(int i  =0;i<n;i++){
            while(!st.empty() && v[st.top()]<v[i]){
                st.pop();
            }
            if(st.empty()){
                prev[i] = -1;
            }
            else{
                prev[i] = st.top();
            }
            st.push(i);
        }

        return prev;
    }
    vector<int> nge(vector<int>&v){
        int n = v.size();
        stack<int>st;
        vector<int> next(n);

        for(int i=v.size()-1;i>=0;i--){
            while(!st.empty() && v[st.top()]<=v[i]){
                st.pop();
            }

            if(st.empty()){
                next[i] = n;
            }
            else{
                next[i] = st.top();
            }

            st.push(i);
        }
        return next;
    }
};