#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
int farthestNode;
int maxDist;

void dfs(int node, int dist) {
    visited[node] = true;

    if (dist > maxDist) {
        maxDist = dist;
        farthestNode = node;
    }

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, dist + 1);
        }
    }
}

int main() {
    int n;
    cin >> n; // number of nodes
    adj.assign(n + 1, {});
    visited.assign(n + 1, false);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // First DFS from node 1
    maxDist = -1;
    dfs(1, 0);

    // Second DFS from farthestNode found above
    visited.assign(n + 1, false);
    maxDist = -1;
    dfs(farthestNode, 0);

    cout << "Tree Diameter: " << maxDist << "\n";
    return 0;
}