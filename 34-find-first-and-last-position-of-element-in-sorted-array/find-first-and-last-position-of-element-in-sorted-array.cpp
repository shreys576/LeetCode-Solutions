class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // vector<int> fin;
        int s = 0;
        int e = nums.size() - 1;
        while(s <= e){
            int mid = (s+e)/2;
            if(nums[mid] == target){
                int l = mid;
                int r = mid;
                while(nums[l] == target){
                    l--;
                    if(l<0)break;
                }
                while(nums[r] == target){
                    r++;
                    if(r>nums.size()-1)break;
                }
                // fin.push_back(l);
                // fin.push_back(r);
                return{l + 1, r - 1};
            }
            else if(nums[mid] < target){
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }
        return {-1, -1};
    }
};