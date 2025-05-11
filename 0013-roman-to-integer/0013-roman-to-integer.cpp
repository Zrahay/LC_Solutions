class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();

        map<char,int>mpp1;

        mpp1['I'] = 1;
        mpp1['X'] = 10;
        mpp1['V'] = 5;
        mpp1['L'] = 50;
        mpp1['C'] = 100;
        mpp1['D'] = 500;
        mpp1['M'] = 1000;
        int sum = 0;

        int i =0;
        while(i < n){
            if((i != n-1) && (s[i] == 'I' && s[i+1] == 'V')){
                sum = sum + 4;
                i = i + 2;
                cout<<sum<<"\n";
            }
            else if((i != n-1) && (s[i] == 'I' && s[i+1] == 'X')){
                sum = sum + 9;
                i = i + 2;
                cout<<sum<<"\n";
            }
            else if((i != n-1) && (s[i] == 'X' && s[i+1] == 'L')){
                sum = sum + 40;
                i =  i + 2;
                cout<<sum<<"\n";
            }
            else if((i != n-1) && (s[i] == 'X' && s[i+1] == 'C')){
                sum = sum + 90;
                 i = i + 2;
                cout<<sum<<"\n";
            }
            else if((i != n-1) && (s[i] == 'C' && s[i+1] == 'D')){
                sum = sum + 400;
                i = i + 2;
                cout<<sum<<"\n";
            }
            else if((i != n-1) && (s[i] == 'C' && s[i+1] == 'M')){
                sum = sum + 900;
                i = i + 2;
                cout<<sum<<"\n";
            }
            else{
                sum = sum + mpp1[s[i]];
                i++;
                cout<<sum<<"\n";
            }

        }
        cout<<sum<<"\n";

        return sum;
    }
};