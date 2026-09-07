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
        int slow = n;
        int fast = sumSquareDigits(n);

        while (slow != fast) {
            fast = sumSquareDigits(sumSquareDigits(fast));
            slow = sumSquareDigits(slow);
        }

        return fast == 1;
    }
};
