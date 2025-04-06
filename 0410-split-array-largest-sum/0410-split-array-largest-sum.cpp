class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high= add(nums);

        while(low<=high){
            int mid = (low)+(high-low)/2;

            int ans= cal(nums, mid);
            if(ans<=k) high=mid-1;
            else low=mid+1;
        }

        return low;
    }
    long long add(vector<int>& v){
        long long sum=0;

        for(int i=0;i<v.size();i++){
            sum+= v[i];
        }

        return sum;
    }

    int cal(vector<int>& v, int mid){
        int partition=1;
        int number=0;

        for(int i=0;i<v.size();i++){
            if((number+v[i])<=mid){
                number+=v[i];
            }
            else{
                partition++;
                number=v[i];
            }
        }

        return partition;
    }
};