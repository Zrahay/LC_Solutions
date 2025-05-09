class Solution {
public:
    int trap(vector<int>& height) {
        int total = 0;

        vector<int>v1 = prefix(height);
        vector<int>v2 = suffix(height);

        for(int i = 0; i < height.size(); i++){
            if(height[i] < v1[i] && height[i] < v2[i]){
                total = total + min(v1[i] , v2[i]) - height[i];
            }
        }

        return total;
    }

    vector<int> prefix(vector<int>& height){
        int n = height.size();
        int maxi = height[0];
        vector<int>ans(n);
        ans[0] = height[0];

        for (int  i = 1; i < height.size(); i++){
            maxi = max(maxi, height[i]);

            ans[i] = maxi;
        }

        return ans;
    }

    vector<int> suffix(vector<int>& height){
        int n = height.size();
        int maxi = height[n-1];
        vector<int>ans(n);
        ans[n-1] = height[n-1];

        for (int i = height.size()-2; i >= 0; i--){
            maxi = max(maxi, height[i+1]);
            ans[i] = maxi;
        }

        return ans;
    }
};