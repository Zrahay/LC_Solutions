class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int n=position.size();
        int low=1;
        int high = position[n-1]-position[0];

        while(low<=high){
            int mid = (low)+(high-low)/2;
            long long ans=  cal(position, mid);

            if(ans>=m) low=mid+1;
            else high=mid-1;
        }

        return high;
    }

    long long cal(vector<int>& v, int mid){
        int ball=1;
        int position=v[0];

        for(int i=1;i<v.size();i++){
            if((v[i]-position)>=mid){
                ball++;
                position=v[i];
            }
            else continue;
        }

        

        return ball;
    }
};