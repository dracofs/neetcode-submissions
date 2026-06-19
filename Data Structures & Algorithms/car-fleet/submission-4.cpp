class Solution {
public:
    bool canCatchUp(double x_0, double x_1, double dest, double v_0, double v_1) {
        if (v_0 <= v_1) return false;
        return (((x_1 - x_0) / (v_0 - v_1)) <= ((dest - x_1) / v_1));
    }

    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        std::vector<pair<int, int>> posSpeed;
        int n = position.size();
        int count = n;
        for (int i = 0; i < n; i++) {
            posSpeed.push_back({position[i], speed[i]});
        }

        std::sort(posSpeed.begin(), posSpeed.end());
        
        for (int i = n - 1; i > 0; i--) {
            if (canCatchUp(posSpeed[i - 1].first, posSpeed[i].first, target, posSpeed[i - 1].second, posSpeed[i].second)) {
                count--;
                posSpeed[i - 1].first = posSpeed[i].first;
                posSpeed[i - 1].second = posSpeed[i].second;
            }
        }
        return count;
    }
};
