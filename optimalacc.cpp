#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dfs(vector<int>& debt, int start) {
        while (start < debt.size() && debt[start] == 0)
            start++;
        if (start == debt.size()) return 0;
        int ans = INT_MAX;
        for (int i = start + 1; i < debt.size(); i++) {
            if (debt[start] * debt[i] < 0) {
                int prev = debt[i];
                debt[i] += debt[start];
                ans = min(ans, 1 + dfs(debt, start + 1));
                debt[i] = prev;
                if (prev + debt[start] == 0) break;
            }
        }
        return ans;
    }
    int minTransfers(vector<vector<int>>& transactions) {
            unordered_map<int,int> balance;
            for (auto &t : transactions)
                balance[t[0]] -= t[2],
                balance[t[1]] += t[2];
            vector<int> debt;
            for (auto &p : balance)
                if (p.second != 0)
                    debt.push_back(p.second);

            return dfs(debt, 0);
    }
};
