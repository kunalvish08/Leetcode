class Solution {
public:
    int characterReplacement(string s, int k) {

        unordered_map<char, int> freq;

        int left = 0;
        int maxFreq = 0;
        int maxLength = 0;

        for (int right = 0; right < s.size(); right++) {

            // Add current character
            freq[s[right]]++;

            // Maximum frequency
            maxFreq = max(maxFreq, freq[s[right]]);

            // Too many replacements required
            while ((right - left + 1) - maxFreq > k) {

                freq[s[left]]--;
                left++;
            }

            // Valid window
            maxLength = max(maxLength,  right - left + 1);
        }

        return maxLength;
    }
};