class Solution {
public:

    string encode(vector<string>& strs) {
		string res;

		for (const string& s : strs) {
			res += to_string(s.size()) + " " + s;
		}

		return res;
}

	vector<string> decode(string encoded) {
		int l = 0, r = 0;
		vector<string> res;
		while (r < encoded.size()) {

			while (encoded[r] != ' ') r++;
			int size = stoi(encoded.substr(l, r - l));
			r++;
			string word = encoded.substr(r, size); 
			r += size;
			l = r;
			res.push_back(word);
		}
		return res;
	}
};
