 class Solution {
public:
    vector<string> ans;

    void solve(string &s, int open, int close, int n) {
        // Base case
        if (s.size() == 2 * n) {
            ans.push_back(s);
            return;
        }

        // We can add '(' if we haven't used all n opening brackets
        if (open < n) {
            s.push_back('(');
            solve(s, open + 1, close, n);
            s.pop_back();
        }

        // We can add ')' only if there is an unmatched '('
        if (close < open) {
            s.push_back(')');
            solve(s, open, close + 1, n);
            s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        string s = "";
        solve(s, 0, 0, n);
        return ans;
    }
};