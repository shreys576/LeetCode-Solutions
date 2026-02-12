class StockSpanner {
public:
vector<int> check;
    StockSpanner() {

    }
    
    int next(int price) {
        check.push_back(price);
        int count = 0;
        int i = check.size() - 1;
        while(i >= 0 && check[i] <= price){
            count++;
            i--;
        }
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */