class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        //if (n<(m*k)) return -1;//Yahan we can do it instead like neeche kiye hai
        long long prod = m;
        prod*= k;
        if(n<prod) return -1;

        int low=*min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        while(low<=high){
            int mid = (low)+(high-low)/2;
            bool ans=possible(bloomDay,mid,m,k);

            if(ans==true) high=mid-1;

            else low=mid+1;
        }
        return low;
    }

    bool possible(vector<int>& bloomDay, int mid, int m, int k){
        long long count=0;
        long long nB=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=mid) count++;

            else{
                nB += (count)/k;
                count=0;
            }
        }
        nB+=count/k;

        if(nB>=m) return true;

        return false;
    }
    
};