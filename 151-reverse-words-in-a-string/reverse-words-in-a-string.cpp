class Solution {
public:
    string reverseWords(string s) {
        stack<string> bank;
        string substr;
        for(auto i : s){
            if(i != ' '){
                substr += i;
            }
            else{
                if(substr.length() > 0){
                    bank.push(substr);
                    substr = "";
                }
            }
        }
        if(substr.length() > 0){
            bank.push(substr);
        }
        string fin ="";
        while(!bank.empty()){
            string temp = bank.top();
            bank.pop();
            fin += temp;
            if(!bank.empty()){
                fin += " ";
            }
        }
        return fin;
    }
};