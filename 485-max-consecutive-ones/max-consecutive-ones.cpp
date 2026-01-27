class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i =0;
        int currentcount = 0;
        int maxcount = 0;
        while(i < nums.size()){
            if(nums[i] == 1){
                currentcount++;
            }
            else{
                maxcount = max(maxcount, currentcount);
                currentcount = 0;
            }
            i++;
        }
        return max(maxcount, currentcount);
    }
};