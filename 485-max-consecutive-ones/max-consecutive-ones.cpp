class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxcount = 0;
        int currentcount = 0;
        for(int i: nums){
            if(i == 1){
                currentcount++;
            }
            else{
                maxcount = max(currentcount, maxcount);
                currentcount = 0;
            }
        }
        maxcount = max(currentcount, maxcount);
        return maxcount;
    }
};