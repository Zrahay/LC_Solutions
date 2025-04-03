class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int low=*max_element(weights.begin(), weights.end());
        cout<<low<<"\n";

        long long high = total(weights, n);
        cout<<high<<"\n";

        while(low<=high){
            int mid = (low)+(high-low)/2;
            cout<<"Mid is : "<<mid<<"\n";
            int ans = cal_days(weights, mid);
            if(ans<=days){
                 high=mid-1;
            }

            else low=mid+1;


        }
        return low;
    }
    long long total(vector<int>& v, int n){
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=v[i];
        }
        return sum;
    }

    int cal_days(vector<int>& v, int capacity){
        int n=v.size();
        int day = 1;
        int sum=0;

        for(int i=0;i<n;i++){
            if(sum+v[i]>capacity){
                day++;
                sum=v[i];
            }
            else {
                sum+=v[i];
            }
        }

        cout<<"Day is : "<<day<<"\n";
        return day;
    }
};