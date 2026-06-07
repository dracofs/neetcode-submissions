class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;

        for (string token : tokens) {
            if (!(token == "+" || token == "-" || token == "/" || token == "*")) nums.push(stoi(token));
            else {
                int n1 = nums.top();
                nums.pop();
                int n2 = nums.top();
                nums.pop();
                int res;

                if (token == "+") {
                    res = n1 + n2;  
                }

                if (token == "-") {
                    res = n2 - n1;
                }

                if (token == "/") {
                    res = n2 / n1;
                }

                if (token == "*") {
                    res = n2 * n1;
                }
                
                nums.push(res);  
            }
        }

        return nums.top();
    }
};
