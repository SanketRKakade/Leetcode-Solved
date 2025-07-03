class Solution {
public:
    char kthCharacter(int k) {
        string s = "a"; 
        while (s.length() <k) {
            string newPart = "";

            for (int i = 0; i < s.length(); i++) {
                newPart +=s[i] + 1;  
            }
            s +=newPart;
        }

        return s[k - 1];  
    }
};
