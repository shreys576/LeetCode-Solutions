class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for(int a : asteroids) {
            bool destroyed = false;

            while(!st.empty() && st.top() > 0 && a < 0) {
                if(st.top() < -a) {
                    st.pop(); // top explodes
                    continue;
                }
                else if(st.top() == -a) {
                    st.pop(); // both explode
                }
                destroyed = true;
                break;
            }

            if(!destroyed) st.push(a);
        }

        vector<int> fin(st.size());
        for(int i = st.size() - 1; i >= 0; i--) {
            fin[i] = st.top();
            st.pop();
        }

        return fin;
    }
};
