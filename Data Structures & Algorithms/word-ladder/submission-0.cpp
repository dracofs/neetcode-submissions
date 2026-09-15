class Solution {
public:
    // a is guaranteed to have same len as b, so i'll not worry
    // about those cases
    bool canConnect(string a, string b) {
        int dif = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) dif++;
        }
        return dif == 1;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (beginWord == endWord) return 0;
        unordered_map<string, vector<string>> adj;
        vector<string> preprocess;
        preprocess.push_back(beginWord);
        for (string& s : wordList) { preprocess.push_back(s); }

        for (int i = 0; i < preprocess.size(); i++) {
            for (int j = i + 1; j < preprocess.size(); j++) {
                if (canConnect(preprocess[i], preprocess[j])) {
                    adj[preprocess[i]].push_back(preprocess[j]);
                    adj[preprocess[j]].push_back(preprocess[i]);
                }
            }
        }

        // ^ fuck you
        unordered_map<string, bool> visited;
        queue<pair<string, string>> q;
        int depth = 1;
        q.push({beginWord, ""});
        visited[beginWord] = true;
        cout << "Traversing: ";
        while (!q.empty()) {
            int len = q.size();

            for (int i{0}; i < len; i++) {
                string curr = q.front().first, parent = q.front().second; q.pop();
                cout << curr << ", ";
                for (string n : adj[curr]) {
                    if (n == endWord) return depth + 1;
                    if (n == parent) continue;
                    if (!visited[n]) {
                        visited[n] = true;
                        q.push({n, curr});
                    }
                }
            }

            depth++;
        }
        return 0;
    }
};
