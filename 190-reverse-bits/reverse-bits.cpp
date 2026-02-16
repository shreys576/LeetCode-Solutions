class Solution {
public:
    int reverseBits(int n) {
        stack<int> st;
        for(int i = 0; i < 32; i++){
            st.push(n & 1);
            n = n >> 1;
        }

        int i = 0;
        int fin = 0;
        while(!st.empty()){
            fin += pow(2,i)* st.top();
            st.pop();
            i++;
        }
        return fin;
    }
};