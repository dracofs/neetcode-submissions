class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (string token : tokens) {
            if (token == "+") {
                int x = s.top(); s.pop();
                int y = s.top(); s.pop();
                s.push(y + x);
            } else if (token == "-") {
                int x = s.top(); s.pop();
                int y = s.top(); s.pop();
                s.push(y - x);
            } else if (token == "*") {
                int x = s.top(); s.pop();
                int y = s.top(); s.pop();
                s.push(y * x);
            } else if (token == "/") {
                int x = s.top(); s.pop();
                int y = s.top(); s.pop();
                s.push(y / x);
            } else s.push(stoi(token));
        }
        return s.top();
    }
};
