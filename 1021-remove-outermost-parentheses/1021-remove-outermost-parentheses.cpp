class Solution {
public:
   string removeOuterParentheses(string s) {
    string res;
    int opened = 0;

    for (auto c : s) {
        if (c == '(') {
            if (opened > 0)
                res += c;
            opened++;
        } else {
            if (opened > 1)
                res += c;
            opened--;
        }
    }

    return res;
}
};