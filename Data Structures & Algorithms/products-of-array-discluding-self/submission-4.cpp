class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
		int n = nums.size();
		vector<int> pre(n);
		vector<int> post(n);
		pre[0] = 1;
		post[n - 1] = 1;

		for (int i = 1; i < n; i++) {
			pre[i] = pre[i - 1] * nums[i - 1];
			post[n - i - 1] = post[n - i] * nums[n - i];
		}

		vector<int> res(n);
		for (int i = 0; i < n; i++) {
			res[i] = pre[i] * post[i];
		}

		return res;
    }
};
