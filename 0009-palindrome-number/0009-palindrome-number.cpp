class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        int original = x;
        long long rev = 0;   // IMPORTANT

        while (x != 0) {
            int ld = x % 10;
            rev = rev * 10 + ld;
            x = x / 10;
        }

        return rev == original;
    }
};
