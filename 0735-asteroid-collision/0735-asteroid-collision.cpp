class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> asteroidStack;

        for (int asteroid : asteroids) {
            bool destroyed = false;
            while (!asteroidStack.empty() && asteroid < 0 && asteroidStack.top() > 0) {
                if (abs(asteroid) > asteroidStack.top()) {
                    asteroidStack.pop();
                } else if (abs(asteroid) == asteroidStack.top()) {
                    asteroidStack.pop();
                    destroyed = true;
                    break;
                } else {
                    destroyed = true;
                    break;
                }
            }

            if (!destroyed) {
                asteroidStack.push(asteroid);
            }
        }

        vector<int> result;
        while (!asteroidStack.empty()) {
            result.insert(result.begin(), asteroidStack.top());
            asteroidStack.pop();
        }

        return result;
    }
};