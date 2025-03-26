class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int n=meetings.size();

        //Most crucial step
        sort(meetings.begin(),meetings.end());

        int start=meetings[0][0];
        int end = meetings[0][1];

        int count=0;
        for(int i=1;i<n;i++){
            int sum=meetings[i][0]-end;

            if(sum<=0){
                end=max(end,meetings[i][1]);
            }
            else{
                count+=end-start+1;
                start=meetings[i][0];
                end=meetings[i][1];
            }
        }

        count+=(end-start+1);
        return (days-count);
    }
};