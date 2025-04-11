class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for (int i = low; i <= high; i++) {

            if (i < 100 && i % 11 == 0) {
                count++;
                continue;
            }
            if(i>=0 && i<=10) continue;
            else if(i>=100 && i<=999) continue;
            int first_two = (i / 1000) + (i / 100) % 10;

            int second_two = (i / 10) % 10 + (i % 10);

            if (first_two == second_two)
                count++;
        }

        return count;
    }
};