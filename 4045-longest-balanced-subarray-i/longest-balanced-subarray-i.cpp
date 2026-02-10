class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int maxlen = 0;
        int curr = 0;
        
        for(int i = 0; i < nums.size() - 1; i++){
            unordered_set<int> even;
            unordered_set<int> odd;
            for(int j = i; j <  nums.size(); j++){
                curr = j - i + 1;
                if(nums[j] % 2 == 0) even.insert(nums[j]);
                else odd.insert(nums[j]);
                if(odd.size() == even.size()) maxlen = max(maxlen, curr);
            }
        }
        return maxlen;
    }
};