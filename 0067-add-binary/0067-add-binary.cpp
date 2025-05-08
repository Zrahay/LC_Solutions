class Solution {
public:
    string addBinary(string a, string b) {
        int max_len = max(a.length(), b.length());
        int diff = abs((int)a.length() - (int) b.length());

        if (a.length() > b.length()){
            b.insert(0, diff , '0');

        }
        else if(b.length() > a.length()){
            a.insert(0, diff, '0');
        }

        cout<<"A is is - > " <<a<<"\n";

        cout<<"B is - > "<<b<<"\n";

        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        int carry = 0;
        string result = "";
        for(int i = 0; i < max_len; i++){
            int sum = carry;
            sum = sum + (a[i] - '0');
            sum = sum + (b[i] - '0');

            carry = sum > 1 ? 1 : 0;
            result = result + to_string(sum % 2);
        }

        if(carry ==1 ) result = result + "1";

        reverse(result.begin(), result.end());

        return result;
    }
};