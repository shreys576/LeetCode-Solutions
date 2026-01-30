class Solution {
public:
    string reverseWords(string s) {
        vector<string> vect;
        string fin = "";
        string str = "";
        for(char i: s){
            if(i == ' '){
                if(str.length() > 0){
                    vect.push_back(str);
                    str = "";
                }
            }
            else{
                str += i;
            }
        }
        if(str.length() > 0){
            vect.push_back(str);
        }
        for(int i = vect.size() - 1; i >0; i--){
            fin += vect[i];
            fin += " ";
        }
        fin += vect[0];
        return fin;
    }
};