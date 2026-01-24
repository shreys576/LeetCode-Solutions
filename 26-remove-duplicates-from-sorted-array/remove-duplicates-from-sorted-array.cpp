class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int j = 0;
        for(int i = 0; i<arr.size(); i++){
            if(arr[j] != arr[i]){
                j++;
                swap(arr[j],arr[i]);
            }
        }
        return j + 1;
    }
};