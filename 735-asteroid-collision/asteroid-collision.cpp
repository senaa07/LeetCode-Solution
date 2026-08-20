class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stk;

        for (int i = 0; i < asteroids.size(); i++) {

            if (asteroids[i] < 0 && !stk.empty() && stk.top() > 0) {
                int flag = 0;
                while (!stk.empty() && stk.top() > 0) {
                    if (stk.top() < abs(asteroids[i])) {
                        stk.pop();
                        flag = 1;
                    }
                    else if (stk.top() == abs(asteroids[i])) {
                        stk.pop();
                        flag = 0;
                        break;
                    }
                    else {
                        flag = 0;
                        break;
                    }
                }
                if (flag)
                    stk.push(asteroids[i]);
            } else {
                stk.push(asteroids[i]);
            }
        }

        int sz = stk.size();
        vector<int> ans(sz);
        for (int i = sz - 1; i >= 0; i--) {
            ans[i] = stk.top();
            stk.pop();
        }

        return ans;
    }
};