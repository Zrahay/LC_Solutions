class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int n = arr.size();

        int final_count = 0;
        
        for(int i =0;i<n-2;i++){
            
            for(int j=i+1;j<n-1;j++){
                for(int k=j+1;k<n;k++){
                    long long count = 0;
                    if(abs(arr[i]-arr[j])<=a) count++;
                    if (abs(arr[j]-arr[k])<=b) count++;
                    if(abs(arr[k]-arr[i])<=c) count++;
                    if(count == 3) final_count++;
                }
                
            }
            
        }

        return final_count;
    }
};