class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> res;
        for (const string& f : folder) {
            if (res.empty() || f.substr(0, res.back().size()) != res.back() || f[res.back().size()] != '/')
                res.push_back(f);
        }
        return res;
    }
};