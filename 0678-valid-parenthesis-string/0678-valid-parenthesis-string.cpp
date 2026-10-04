 class Solution {
public:
    bool checkValidString(string s) {
        int low = 0;
        int high = 0;

        for (char ch : s) {

            if (ch == '(') {
                low++;
                high++;
            }
            else if (ch == ')') {
                low--;
                high--;
            }
            else { // '*'
                low--;   // '*' acts as ')'
                high++;  // '*' acts as '('
            }

            // Even maximum possible opens became negative
            if (high < 0) {
                return false;
            }

            // Minimum cannot go below 0
            low = max(low, 0);
        }

        return low == 0;
    }
};