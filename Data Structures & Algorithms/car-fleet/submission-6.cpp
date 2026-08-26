class Solution {
public:
    bool can_catch(auto& cars, int a, int b, int target) {
        double time_a = (target - cars[a].first) / (double)cars[a].second;
        double time_b = (target - cars[b].first) / (double)cars[b].second;
        return time_b <= time_a;
    }

    int carFleet(int target, vector<int>& position, vector<int>& speed) {  
        int n = position.size();     
        vector<pair<int, int>> cars(n);
        for (int i = 0; i < n; i++) {
            cars[i] = {position[i], speed[i]};
        }
        sort(cars.begin(), cars.end());
        
        int res = n;
        for (int i = n - 1; i >= 1; i--) {
            if (can_catch(cars, i, i - 1, target)) {
                res--;
                cars[i - 1] = cars[i];
            }
        }
        return res;
    }
};
