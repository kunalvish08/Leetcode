class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> degree(n, 0);
        unordered_set<long long> connected;

        for (auto &road : roads) {
            int u = road[0];
            int v = road[1];

            degree[u]++;
            degree[v]++;

            long long key = 1LL * min(u, v) * n + max(u, v);
            connected.insert(key);
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int rank = degree[i] + degree[j];

                long long key = 1LL * i * n + j;
                if (connected.count(key))
                    rank--;

                ans = max(ans, rank);
            }
        }

        return ans;
    }
};