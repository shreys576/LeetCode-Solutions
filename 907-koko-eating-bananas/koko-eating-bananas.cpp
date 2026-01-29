class Solution {
public:

    int findMax(vector<int>& piles){
        int maxi = 0;
        for(int i = 0;i<piles.size();i++){
            maxi = max(maxi, piles[i]);
        }
        return maxi;
    }

    long long findTime(vector<int>& piles, int k){
        long long time = 0;
        for(int i = 0; i< piles.size(); i++){
            time += ceil(double(piles[i]) / k);
        }
        return time;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = findMax(piles);
        int l = 1;
        int r = maxi;
        int ans = 0;

        while(l<=r){
            int mid = (l+r)/2;
            long long time = findTime(piles, mid);
            if(time <= h){
                r = mid - 1;
                ans = mid;
            }
            else{
                l = mid + 1;
            }
        }
        return ans;
    }
};