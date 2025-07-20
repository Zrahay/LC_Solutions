class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int start_sum = 0;
        int maxi = INT_MIN;

        // Pehle starting k leke dekho
        for(int i = 0; i < k; i++){
            start_sum += cardPoints[i];
            maxi = max(maxi, start_sum);
        }

        // Now we need to go for and select the last k elements and alongside also left kum karke right badha dene ka
        
        int j = cardPoints.size() - 1;
        k--;
        while(k >= 0){
            start_sum -= cardPoints[k--];
            start_sum = start_sum + cardPoints[j];

            maxi = max(maxi, start_sum);
            j--;
        }

        return maxi;
    }
};