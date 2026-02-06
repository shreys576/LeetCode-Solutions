class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = nums1.size();
        int j = nums2.size();
        int k = i + j;
        vector<int> fin(k, 0);
        i--;
        j--;
        k--;
        while(j >= 0 && i >= 0){
            if(nums1[i] > nums2[j]){
                fin[k--] = nums1[i--];
            }
            else{
                fin[k--] = nums2[j--];
            }
        }
        while(j>=0) fin[k--] = nums2[j--];
        while(i>=0) fin[k--] = nums1[i--];
        double median;
        if(fin.size()%2!=0){
            int index = fin.size()/2;
            median = fin[index];
        }
        else{
            int index = fin.size()/2;
            median = (fin[index] + fin[index - 1])/2.0;
        }
        return median;
    }
};