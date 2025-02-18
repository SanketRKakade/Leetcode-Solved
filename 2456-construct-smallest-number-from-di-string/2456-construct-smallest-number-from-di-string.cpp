// class Solution {
// public:
//     string smallestNumber(string pattern) {
//         stack<char>st;
//         string ans = "";
//         st.push(1+'0');
//         for(int i=0 ; i<pattern.size() ; i++){
//             if(pattern[i]=='I'){
//                 char ch = st.top();
//                 st.pop();
//                 ans+=ch;
//                 st.push((i+2)+'0');
//             }
//             else{
//                 st.push((i+2)+'0');
//                 char ch = st.top();
//                 st.pop();
//                 ans+=ch;
//                 if(st.empty()) st.push(pattern.size()+1+'0');
                
//             }
//         }
//         while(!st.empty()){
//             ans+=st.top();
//             st.pop();
//         }
//         return ans;
//     }
// };

class Solution {
public:
    string smallestNumber(string pattern) {
        stack<int> st;
        string ans = "";
        
        for (int i = 0; i <= pattern.size(); i++) {
            st.push(i + 1); 
            
            if (i == pattern.size() || pattern[i] == 'I') {
                while (!st.empty()) {
                    ans += (st.top() + '0');
                    st.pop();
                }
            }
        }
        
        return ans;
    }
};
