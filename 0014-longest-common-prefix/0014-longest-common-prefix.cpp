class Solution {
public:
   string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty())
        return "";

    sort(strs.begin(), strs.end());

    int first = 0, last = strs.size() - 1;
    int i = 0, j = 0;
    int len = 0;

    while (i < strs[first].size() && j < strs[last].size() && strs[first][len] == strs[last][len]) {
        i++;
        j++;
        len++;
    }

    return strs[first].substr(0, len);
}
};