class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int low=1;
        long long high=ME(piles);

        
        while(low<=high){
            long long mid = low+(high-low)/2;
            long long th = Totalhours(piles,mid);
            if(th<=h){
                
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }

        return low;
    }

    int ME(vector<int>& v){
        int maxi=INT_MIN;
        for(int i=0;i<v.size();i++){
            if(v[i]>maxi){
                maxi=v[i];
            }
        }
        return maxi;
    }

    long long Totalhours(vector<int>& v, int hourlyrate){
        long long total=0;
        for(int i=0;i<v.size();i++){
            total+= ceil((double)(v[i])/(double)(hourlyrate));
        }

        return total;
    }


};