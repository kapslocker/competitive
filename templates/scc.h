#include <bits/stdc++.h>
using namespace std;

void dfs(unordered_map<int, vector<int>> &graph, vector<bool> &visited,
         stack<int> &order, int u) {
  if (visited[u])
    return;
  visited[u] = true;
  for (int v : graph[u]) {
    dfs(graph, visited, order, v);
  }
  order.push(u);
}

void assign(unordered_map<int, vector<int>> &rev_graph,
            unordered_map<int, vector<int>> &component,
            vector<bool> &is_assigned, int u, int root) {
  if (is_assigned[u])
    return;
  is_assigned[u] = true;
  component[root].push_back(u);
  for (int v : rev_graph[u])
    assign(rev_graph, component, is_assigned, v, root);
}

void scc(unordered_map<int, vector<int>> &graph,
         unordered_map<int, vector<int>> &rev_graph,
         unordered_map<int, vector<int>> &component, int n) {
  vector<bool> visited(n + 1);
  stack<int> order;
  for (int i = 0; i <= n; i++) {
    dfs(graph, visited, order, i);
  }
  for (int i = 0; i <= n; i++) {
    visited[i] = !visited[i];
  }
  while (!order.empty()) {
    int v = order.top();
    order.pop();
    assign(rev_graph, component, visited, v, v);
  }
}
