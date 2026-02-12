class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sumg = 0;
        int sumc = 0;
        for(int i = 0; i < gas.size(); i++){
            sumg += gas[i];
            sumc += cost[i];
        }
        if(sumg < sumc) return -1;

        int balance = 0;
        int total = 0;
        int curr = 0;
        int start = 0;
        for(int i =0; i < gas.size(); i++){
            balance = gas[i] - cost[i];
            total += balance;
            curr += balance;

            if(curr < 0){
                start = i + 1;
                curr = 0;
            }
        }

        if(total < 0) return -1;
        return start;
    }
};