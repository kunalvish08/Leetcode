class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;

        for (char ch : s) {
            if (!st.empty() && st.top().first == ch) {
                st.top().second++;

                if (st.top().second == k)
                    st.pop();
            } else {
                st.push({ch, 1});
            }
        }

        string ans;

        while (!st.empty()) {
            char ch = st.top().first;
            int cnt = st.top().second;
            st.pop();

            ans = string(cnt, ch) + ans;
        }

        return ans;
    }
};