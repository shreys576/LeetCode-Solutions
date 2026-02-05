class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        vector<int> result(nums.size(), 0);
        for(int i = 0; i < nums.size(); i++){
            int index = nums[i];
            if(index > 0){
                int findex = index + i;
                if(findex >= nums.size()){
                    findex = findex % nums.size();
                }
                result[i] = nums[findex];
            }
            else{
                index = abs(index);
                int findex = i - index;
                if(findex < 0){
                    do{
                        findex += nums.size();
                    }
                    while(findex < 0);
                }
                if(findex >= nums.size()){
                    findex = findex % nums.size();
                }
                result[i] = nums[findex];

            }
        }
        return result;
    }
};