#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int dfs(map<int, vector<int> > &tree, int v, vector<bool> &visited) {
    int ans = 0;
    visited[v] = true;
    for(int& u : tree[v]) {
        if(visited[u])
            continue;
        int x = dfs(tree, u, visited);
        ans = max(ans, x);
    }
    return 1 + ans;
}

int check(map<int, vector<int> > &tree, int s) {
    int largest_size = 0, n = tree.size(), center;
    vector<bool> visited(n + 1, false);
    visited[s] = true;
    for(int &v : tree[s]) {
        int sz = dfs(tree, v, visited);
        if(sz > largest_size) {
            largest_size = sz;
            center = v;
        }
    }
    if(2 * largest_size <= n)
        return -1;
    return center;
}

int centroid_tree(map<int, vector<int> > &tree) {
    int current = 1, found = false;
    while(!found) {
        int resp = check(tree, current);
        if(resp == -1)
            return current;
        current = resp;
    }
}
