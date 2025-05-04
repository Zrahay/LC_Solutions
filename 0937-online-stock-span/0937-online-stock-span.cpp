class StockSpanner {
    private:
    stack<pair<int,int>>st;
    int call;
public:
    StockSpanner() {
        call=0;
        
    }
    
    int next(int price) {
        int ans;
        while(!st.empty() && (st.top().first<=price)){
            st.pop();
        }
        if(st.empty()){
            ans = call - (-1);
        }
        else{
            ans=  call - st.top().second;
        }
        st.push({price,call});
        call++;
        return ans;
    }


};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */