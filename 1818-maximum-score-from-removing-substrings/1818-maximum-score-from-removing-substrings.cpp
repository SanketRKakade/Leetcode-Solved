class Solution {
private:
    string removeSubstring(const string& s, const string& pattern, int value, int& points) {
        string res;
        for (char ch : s) {
            if (!res.empty() && res.back() == pattern[0] && ch == pattern[1]) {
                res.pop_back(); 
                points += value;
            } else {
                res += ch;
            }
        }
        return res;
    }

public:
    int maximumGain(string s, int x, int y) {
        int points = 0;

        if (x > y) {
            s = removeSubstring(s, "ab", x, points);
            s = removeSubstring(s, "ba", y, points);
        } else {
            s = removeSubstring(s, "ba", y, points);
            s = removeSubstring(s, "ab", x, points);
        }

        return points;
    }
};
