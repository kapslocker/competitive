#include <bits/stdc++.h>
using namespace std;

void dfs(map<int, vector<int> > &graph, int s, vector<int> &visited, int mark) {
    if(visited[s])
        return;
    visited[s] = mark;
    for(auto &v : graph[s]) {
        dfs(graph, v, visited, mark);
    }
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k, ans = 0;
    cin >> n >> k;
    map<int, vector<int> > graph;
    for(int i = 0; i < k; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<int> visited(n + 1, false);
    for(int i = 1; i <= n; i++) {
        dfs(graph, i, visited, i);
    }
    map<int, int> sizes;
    for(int x:visited) {
        sizes[x]++;
    }
    for(auto &x : sizes)
        ans += x.second - 1;
    cout << k - ans << endl;
    return 0;
}
