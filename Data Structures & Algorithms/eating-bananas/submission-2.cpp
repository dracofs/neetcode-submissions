class Solution {
public:
    bool eat(vector<int>& piles, int rate, int limit) { 
        int time = 0;

        for (int banana : piles) {
            time += banana / rate;
            if (banana % rate != 0) time += 1;
        }

        return time <= limit;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1;
        int hi = *max_element(piles.begin(), piles.end());
        int best = hi;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (eat(piles, mid, h)) {
                best = min(best, mid);
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        return best;
    }
};
