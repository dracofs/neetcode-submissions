class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n + 1);
        res[0] = 0;

        for (int i = 1; i <= n; i++) {
            res[i] = countOnes(i);
        }

        return res;
    }

    int countOnes(int num) {
        int res = 0;
        while (num) {
            if (num % 2 == 1) res++;
            num = num >> 1;
        }
        return res;
    }
};
