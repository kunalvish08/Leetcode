class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        
        if (s.length() < p.length()) return ans;

        vector<int> pCount(26, 0), windowCount(26, 0);

        // Frequency of p
        for (char ch : p) {
            pCount[ch - 'a']++;
        }

        int k = p.length();

        for (int i = 0; i < s.length(); i++) {
            // Add current character to window
            windowCount[s[i] - 'a']++;

            // Remove character if window size exceeds k
            if (i >= k) {
                windowCount[s[i - k] - 'a']--;
            }

            // Compare when window size becomes k
            if (windowCount == pCount) {
                ans.push_back(i - k + 1);
            }
        }

        return ans;
    }
};