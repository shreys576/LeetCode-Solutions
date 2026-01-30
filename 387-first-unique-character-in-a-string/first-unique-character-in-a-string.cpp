class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> freq(26, 0);
        string str = "";
        for(char i: s){
            freq[i - 'a']++;
        }
        for(char i : s){
            if(freq[i - 'a'] == 1){
                str += i;
                break; 
            }
        }
        if(str.length() > 0){
            return s.find(str);
        }
        else{
            return -1;
        }
    }
};