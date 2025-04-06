class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int low=1;
        int high=*max_element(quantities.begin(), quantities.end());

        while(low<=high){
            int mid = (low)+(high-low)/2;
            int ans = cal(quantities, mid);

            if(ans<=n) high=mid-1;

            else low=mid+1;
        }

        return low;
    }

    int cal(vector<int>& v, int mid){
        int stores=0;

        for(int i=0;i<v.size();i++){
            stores+= ceil((double)v[i]/(double)(mid));
        }

        return stores;
    }
};