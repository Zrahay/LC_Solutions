class Solution {
public:
    int lastRemaining(int n) {

        if(n == 1) return 1;

        int i = 1;
        int head = 1;
        int diff = 1;

        while(n != 1){
            if((i & 1) || (n & 1)){
                head = head + diff;
                
            }

            diff *= 2;
            cout<<n<<"\n";
            n = n / 2;
            
            i++;
        }

        return head;
    }
};