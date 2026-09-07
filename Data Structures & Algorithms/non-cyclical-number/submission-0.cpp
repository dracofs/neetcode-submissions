class Solution {
public:
    int sumSquareDigits(int n) {
        int sum = 0;
        while (n > 0) {
            int last = n % 10;
            sum += last * last;
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        unordered_set<int> seen;

        while (n != 1) {
            if (seen.contains(n)) return false;
            seen.insert(n);
            n = sumSquareDigits(n);
        }

        return true;
    }
};
