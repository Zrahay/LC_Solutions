class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>nse_index = nse(heights);
        vector<int>pse_index = pse(heights);

        int maxi = INT_MIN;
        for(int i = 0; i < n; i++){
            int res1 = (heights[i])*(nse_index[i] - pse_index[i] - 1);
            maxi = max(maxi , res1);
            cout<<maxi<<"\n";
        }

        return maxi;
    }

    vector<int> nse(vector<int>& heights){
        int n = heights.size();
        stack<int>st;
        vector<int>nse_indexed(n);

        for(int i = n-1; i >=0; i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()==true){
                nse_indexed[i] = n;
            }
            else{
                nse_indexed[i] = st.top();
            }
            st.push(i);
        }
        return nse_indexed;
    }

    vector<int> pse(vector<int>& heights){
        int n = heights.size();
        stack<int>st;
        vector<int>pse_indexed(n);

        for(int i = 0;i < n; i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                st.pop();
            }
            if(st.empty()){
                pse_indexed[i] = -1;
            }
            else{
                pse_indexed[i] = st.top();
            }
            st.push(i);
        }

        return pse_indexed;
    }
};