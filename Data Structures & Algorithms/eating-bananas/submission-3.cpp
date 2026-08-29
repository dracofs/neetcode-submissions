class Solution {
public:
    const bool canEat(const vector<int>& piles, int hours, int rate) {
        int time = 0;

        for (const int bananas : piles) {
            time += bananas / rate;
            if (bananas % rate != 0) time += 1;
        }

        return time <= hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        // lowest possible rate is 1, max is *max_element(piles)
        int l = 1, r = *max_element(piles.begin(), piles.end());
        int res = 1;
        while (l <= r) {
            int mid = (l + r) / 2;

            if (canEat(piles, h, mid)) {
                res = mid;
                r = mid - 1;
            } else l = mid + 1;
        }

        return res;
    }
};
