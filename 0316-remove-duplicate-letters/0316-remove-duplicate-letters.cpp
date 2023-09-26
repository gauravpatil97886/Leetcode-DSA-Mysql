class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> cnt(26, 0), vis(26, 0);
        int n = s.size();
        
        for (int i = 0; i < n; ++i)
            cnt[s[i] - 'a']++;
        
        stack<char> st;
        
        for (int i = 0; i < n; ++i) {
            cnt[s[i] - 'a']--;
            
            if (!vis[s[i] - 'a']) {
                while (!st.empty() && st.top() > s[i] && cnt[st.top() - 'a'] > 0) {
                    vis[st.top() - 'a'] = 0;
                    st.pop();
                }
                
                st.push(s[i]);
                vis[s[i] - 'a'] = 1;
            }
        }
        
        string res = "";
        while (!st.empty()) {
            res = st.top() + res;
            st.pop();
        }
        
        return res;
    }
};
