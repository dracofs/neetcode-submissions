class Solution {
public:
    bool canOvertake(pair<double,double> speeds, pair<double, double> positions, double target) {
        return (speeds.first > speeds.second &&
        (positions.second - positions.first)/(speeds.first - speeds.second) <= ((target - positions.second)/speeds.second));

    }
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int size = position.size();
        vector<pair<int, int>> pos_speed(size, {0, 0});

        for (int i = 0; i < size; ++i) {
            pos_speed[i] = {position[i], speed[i]};
        } 

        std::sort(pos_speed.begin(), pos_speed.end());

        int total_fleets = size;

        for (int i = size - 1; i > 0; i--) {
            
            if (canOvertake({pos_speed[i - 1].second, pos_speed[i].second}, {pos_speed[i - 1].first, pos_speed[i].first}, target)) {
                pos_speed[i - 1] = pos_speed[i];
                total_fleets--;
            }
        }

        return total_fleets;
    }
};
