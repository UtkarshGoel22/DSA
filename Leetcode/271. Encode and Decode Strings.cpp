class Solution {
public:
    string encode(vector<string>& strs) {
        int n = strs.size();
        string res = "";
        for (int i = 0; i < n; i++) {
            res += to_string(strs[i].size()) + "#" + strs[i];
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0, n = s.size();
        while (i < n) {
            int j = i;
            while (s[j] != '#') j++;
            int length = stoi(s.substr(i, j-i));
            string str = s.substr(j+1, length);
            res.push_back(str);
            i = j+1+length;
        }
        return res;
    }
};
