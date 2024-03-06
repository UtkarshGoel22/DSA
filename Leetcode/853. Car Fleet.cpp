// Using stack
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // TC: O(NlogN), SC: O(N + N)
        int n = position.size(), ans = 0;
        stack<float> st;
        vector<pair<int, float>> time(n);
        for (int i = 0; i < n; i++) {
            time[i] = {position[i], (float(target - position[i])) / speed[i]};
        }
        sort(time.begin(), time.end());
        for (auto x : time) st.push(x.second);
        while (!st.empty()) {
            float top = st.top();
            st.pop();
            while (!st.empty() && st.top() <= top) st.pop();
            ans++;
        }
        return ans;
    }
};

// Without using stack
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // TC: O(NlogN), SC: O(N)

        int n = position.size(), ans = 0;
        vector<pair<int, float>> cars;
        for (int i = 0; i < n; i++) {
            cars.push_back({position[i], (target-position[i])/float(speed[i])});
        }
        sort(cars.begin(), cars.end());
        float maxTime = 0;
        for (int i = n-1; i >= 0; i--) {
            if (cars[i].second > maxTime) {
                maxTime = cars[i].second;
                ans++;
            }
        }
        return ans;
    }
};
