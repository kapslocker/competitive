#include <bits/stdc++.h>
using namespace std;


void dfs_test(vector<vector<int> > &graph, vector<int> &parent, vector<bool> &visited, int u, int dest, int flag, bool &reached, bool &ans){
    if(!ans)
        return;
    if(visited[u])
        return;
    visited[u] = true;
    for(auto v : graph[u]){
        if(v == dest){
            cout << "yay" << endl;
            if(flag || reached){
                ans = false;
                return;
            }
            reached = true;
        }
        else{
            int x = parent[v];
            if(!x){
                parent[v] = u;
                dfs_test(graph, parent, visited, v, dest, flag, reached, ans);
            }
            else if(x != u && v != parent[u]){
                cout << "here " << v << " " << u << " " << x << endl;
                dfs_test(graph, parent, visited, v, dest, true, reached, ans);
            }
        }
    }
}
int main(){
    int n, m, q, x, y;
    cin >> n >> m >> q;
    vector<vector<int> > graph(n + 1);
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    for(int i = 0; i < q; i++){
        cin >> x >> y;
        bool ans = true, reached = false;
        vector<int> parent(n + 1);
        vector<bool> visited(n + 1);
        dfs_test(graph, parent, visited, x, y, false, reached, ans);
        cout << (ans && reached) << endl;
    }
    return 0;
}
