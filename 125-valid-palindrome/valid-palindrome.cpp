class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";
        for(char i: s){
            if(isalnum(i)){
                str.push_back(tolower(i));
            }
        }
        string p = str;
        int l = 0;
        int r = p.length() - 1;
        while(l<r){
            swap(p[l],p[r]);
            l++;
            r--;
        }
        return p == str;
    }
};