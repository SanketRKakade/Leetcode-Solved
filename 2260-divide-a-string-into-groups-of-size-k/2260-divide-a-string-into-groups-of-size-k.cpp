class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        string a = "";

        for (int i = 0; i < s.length(); i++) {
            a += s[i];
            if (a.length() == k) {
                ans.push_back(a);
                a = "";
            }
        }

        if (a.length() != 0) {
            while (a.length() < k) {
                a += fill;
            }
            ans.push_back(a);
        }

        return ans;
    }
};