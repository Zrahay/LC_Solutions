class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<vector<int>>ans;

        sort(intervals.begin(), intervals.end());

        for(int i = 0 ; i < n ;i++){
            if(ans.empty()){
                ans.push_back(intervals[i]);
            }

            else{
                vector<int>& v = ans.back();
                int y = v[1];
                int maxi;
                int x = intervals[i][0];

                if(x <= y){
                    maxi = max(y, intervals[i][1]);
                    v[1] = maxi;
                }

                else{
                    ans.push_back(intervals[i]);
                }
            }
        }

        return ans;
    }
};