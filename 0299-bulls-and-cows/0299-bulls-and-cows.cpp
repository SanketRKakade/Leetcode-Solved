class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.length(),bulls=0,cows=0;
        vector<bool> isbull(n,false);
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++) {
            if(secret[i] == guess[i]) {
                isbull[i] = true;
                bulls++;
            }else {
                mp[secret[i]]++;
            }
        }

        for(int i=0;i<n;i++) {
            if(!isbull[i]) {
                if(mp.find(guess[i])!=mp.end() && mp[guess[i]] > 0) {
                    mp[guess[i]]--;
                    cows++;
                }
            }
        }

        return to_string(bulls) + 'A' + to_string(cows) + 'B';
    }
};