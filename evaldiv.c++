class Solution {
public:
    unordered_map<string, vector<pair<string,double>>> graph;

    void addEdge(string a, string b, double val) {
        graph[a].push_back({b, val});
        graph[b].push_back({a, 1.0 / val});
    }

    bool dfs(string curr, string target, unordered_set<string>& visited, double& prod) {
        if(curr == target) return true;
        visited.insert(curr);

        for(auto &neighbor : graph[curr]) {
            string next = neighbor.first;
            double weight = neighbor.second;

            if(visited.count(next)) continue;

            prod *= weight;
            if(dfs(next, target, visited, prod)) return true;
            prod /= weight; // backtrack
        }

        return false;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        graph.clear();
        int n = equations.size();

        // build graph
        for(int i = 0; i < n; i++)
            addEdge(equations[i][0], equations[i][1], values[i]);

        vector<double> res;
        for(auto &q : queries) {
            string start = q[0], end = q[1];

            if(!graph.count(start) || !graph.count(end)) {
                res.push_back(-1.0);
                continue;
            }

            double prod = 1.0;
            unordered_set<string> visited;
            if(dfs(start, end, visited, prod))
                res.push_back(prod);
            else
                res.push_back(-1.0);
        }

        return res;
    }
};
