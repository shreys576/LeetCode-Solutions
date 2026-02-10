class Solution {
public:
    bool isValid(string s) {
        stack<char> open;
        bool flag = false;
        for(auto i : s){
            if(i == '(' || i == '{' || i == '['){
                open.push(i);
            }
            else{
                if(open.empty()) return false;
                if((open.top() == '(' && i == ')') || (open.top() == '[' && i == ']') || (open.top() == '{' && i == '}')){
                    flag = true;
                }
                else{
                    return false;
                }
                open.pop();
            }
        }
        if(!open.empty()) return false;
        return flag;
    }
};