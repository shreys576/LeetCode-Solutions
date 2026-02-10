class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char fin = letters[0];
        int mini = INT_MAX;
        for(auto i : letters){
            if(i - target > 0){
                if(i - target < mini){
                    fin = i;
                    mini = i - target;
                }
            }
        }
        return fin;
    }
};