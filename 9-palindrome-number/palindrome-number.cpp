class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        string p = s;
        int l = 0;
        int r = p.length() - 1;
        while(l<r){
            swap(p[l],p[r]);
            l++;
            r--;
        }
        return p == s;
    }
};