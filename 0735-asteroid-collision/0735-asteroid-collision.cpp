class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();

        stack<int> st;

        for (int i = 0; i < n; i++) {
            if (asteroids[i] > 0) {
                st.push(asteroids[i]);
            } 
            else if(!st.empty() && st.top() > 0 && abs(asteroids[i]) == st.top()){
                st.pop();
            }
            else {
                if(asteroids[i] < 0) {
                    bool flag = false;
                    while (!st.empty() && st.top() > 0) {
                        
                        int diff = st.top() - abs(asteroids[i]);

                        if (diff < 0) {
                            st.pop();
                        }
                        else if(diff == 0){
                            st.pop();
                            flag = true;
                            break;
                        }
                        else break;
                    }
                    if((st.empty() || st.top() < 0 ) && flag==false){
                    st.push(asteroids[i]);
                }
                    
                }
                
            }
        }

        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};