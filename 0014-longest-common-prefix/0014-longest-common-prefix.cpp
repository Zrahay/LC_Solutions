class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());

        string s1 = strs[0];
        int n = strs.size();
        string s2 = strs[n-1];

        int i = 0;
        int j = 0;
        int n1 = s1.length();
        int n2 = s2.length();

        int count = 0;

        int len = min(n1,n2);

        for(int i = 0; i < len ;i++){
            if(s1[i] != s2[i]) break;
            else count++;
        }

        cout<<"Count is -> "<<count<<"\n";
        if(count == 0) return "";
        string result = "";

        for(int i = 0; i < count; i++){
            result = result + s1[i];
        }

        return result;
    }
};