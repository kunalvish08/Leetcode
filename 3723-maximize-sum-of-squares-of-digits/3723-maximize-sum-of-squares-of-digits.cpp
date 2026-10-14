
class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans = "";

        if (sum > num * 9) return "";

        while (sum > 0 && num > 0) {
            int digit = min(9, sum);
            ans += to_string(digit);
            sum -= digit;
            num--;
        }

        while (num > 0) {
            ans += '0';
            num--;
        }

        return ans;
    }
};
