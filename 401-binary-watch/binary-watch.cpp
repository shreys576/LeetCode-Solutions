class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {

        vector<vector<string>> table(11);

        for(int h = 0; h < 12; h++) {
            for(int m = 0; m < 60; m++) {
                int bits = __builtin_popcount(h) + __builtin_popcount(m);

                string time = to_string(h) + ":";
                if(m < 10) time += "0";
                time += to_string(m);

                table[bits].push_back(time);
            }
        }

        return table[turnedOn];
    }
};
