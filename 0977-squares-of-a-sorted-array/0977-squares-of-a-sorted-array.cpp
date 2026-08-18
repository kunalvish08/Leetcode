 class Solution {
public:
    vector<int> sortedSquares(vector<int>& a) {
        int n = a.size();

        vector<int> neg;
        vector<int> pos;

        // Split negative and positive
        for (int x : a) {
            if (x < 0)
                neg.push_back(x);
            else
                pos.push_back(x);
        }

        // Square negative part
        for (int i = 0; i < neg.size(); i++)
            neg[i] *= neg[i];

        // Make negative squares sorted
        reverse(neg.begin(), neg.end());

        // Square positive part
        for (int i = 0; i < pos.size(); i++)
            pos[i] *= pos[i];

        // Merge two sorted arrays
        vector<int> res;
        int i = 0, j = 0;

        while (i < neg.size() && j < pos.size()) {
            if (neg[i] <= pos[j])
                res.push_back(neg[i++]);
            else
                res.push_back(pos[j++]);
        }

        while (i < neg.size())
            res.push_back(neg[i++]);

        while (j < pos.size())
            res.push_back(pos[j++]);

        return res;
    }
};