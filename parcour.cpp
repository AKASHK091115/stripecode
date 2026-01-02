class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> graph(n);
        vector<int> indeg(n, 0);
        for (auto &r : relations) {
            int u = r[0] - 1;
            int v = r[1] - 1;
            graph[u].push_back(v);
            indeg[v]++;
        }
        vector<int> dist = time;
        queue<int> q;
        for (int i = 0; i < n; i++)
            if (indeg[i] == 0)
                q.push(i);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : graph[u]) {
                dist[v] = max(dist[v], dist[u] + time[v]);
                if (--indeg[v] == 0)
                    q.push(v);
            }
        }
        return *max_element(dist.begin(), dist.end());
    }
};
