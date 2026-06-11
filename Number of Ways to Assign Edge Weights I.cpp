class Solution {
    public:
        int assignEdgeWeights(vector<vector<int>>& edges) {
            vector<vector<int>> adj(edges.size() + 2);
            for (auto it : edges) {
                adj[it[0]].push_back(it[1]);
                adj[it[1]].push_back(it[0]);
            }
            vector<int> vis(edges.size() + 2, 0);
            queue<int> qu;
            qu.push(1);
            vis[1] = 1;
            int level = 0, ans = 1, mod = 1e9 + 7;
            while (!qu.empty()) {
                int size = qu.size();
                while (size--) {
                    int ele = qu.front();
                    qu.pop();
                    for (auto adjac : adj[ele]) {
                        if (!vis[adjac]) {
                            qu.push(adjac);
                            vis[adjac] = 1;
                        }
                    }
                }
                level++;
            }
            for (int i = 1; i < level - 1; i++) {
                ans = (ans << 1) % mod;
            }
            return ans;
        }
    };