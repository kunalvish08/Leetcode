class Solution {
public:
    vector<string> ans;

    void solve(string s, int start, int leftRem, int rightRem) {
        if (leftRem == 0 && rightRem == 0) {
            int balance = 0;

            for (char c : s) {
                if (c == '(') balance++;
                else if (c == ')') balance--;

                if (balance < 0) return;
            }

            if (balance == 0)
                ans.push_back(s);

            return;
        }

        for (int i = start; i < s.size(); i++) {

            // Remove duplicate parentheses choices
            if (i > start && s[i] == s[i - 1])
                continue;

            // Remove '('
            if (leftRem > 0 && s[i] == '(') {
                string temp = s.substr(0, i) + s.substr(i + 1);
                solve(temp, i, leftRem - 1, rightRem);
            }

            // Remove ')'
            if (rightRem > 0 && s[i] == ')') {
                string temp = s.substr(0, i) + s.substr(i + 1);
                solve(temp, i, leftRem, rightRem - 1);
            }
        }
    }

    vector<string> removeInvalidParentheses(string s) {

        int leftRem = 0;
        int rightRem = 0;

        // Find minimum parentheses that must be removed
        for (char c : s) {
            if (c == '(') {
                leftRem++;
            }
            else if (c == ')') {
                if (leftRem > 0)
                    leftRem--;
                else
                    rightRem++;
            }
        }

        solve(s, 0, leftRem, rightRem);

        return ans;
    }
};