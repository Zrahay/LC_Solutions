class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int mod = 1e9+7;
        long long sum = 0;
        vector<int> nse_index = nse(arr);
        vector<int>pse_index = pse(arr);

        for(int i = 0;i<n;i++){
            int res1 = i - pse_index[i];
            int res2 = nse_index[i] - i;
            sum = (sum + (1LL*arr[i]*res1*res2))%mod;
        }
        return sum;
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
};