class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();

        unordered_map<int, vector<int>> mp;

        // Store elements of each diagonal
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mp[i - j].push_back(mat[i][j]);
            }
        }

        // Sort each diagonal in descending order
        for (auto &it : mp) {
            sort(it.second.begin(), it.second.end(), greater<int>());
        }

        // Fill matrix back
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mat[i][j] = mp[i - j].back();
                mp[i - j].pop_back();
            }
        }

        return mat;
    }
};