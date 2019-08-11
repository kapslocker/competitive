#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int> > &tree, vector<int> &colors, int currcolor, int u, vector<bool> &visited, int &ans){
    if(visited[u])
        return;
    if(!visited[u]){
        int c = colors[u];
        if(c != currcolor){
            ans++;
            currcolor = c;
        }
        visited[u] = true;
        for(int i = 0; i < tree[u].size(); i++){
            dfs(tree, colors, currcolor, tree[u][i], visited, ans);
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);
    vector<vector<int> > tree(n + 1);
    for(int i = 2; i <= n; i++){
        int x;
        scanf("%d", &x);
        tree[x].push_back(i);
        tree[i].push_back(x);
    }
    vector<int> colors(n + 1);
    for(int i = 1; i <= n; i++){
        scanf("%d", &(colors[i]));
    }

    int ans = 0;
    stack<int> s;
    vector<bool> visited(n + 1, 0);
    dfs(tree, colors, 0, 1, visited, ans);
    cout << ans << endl;
    return 0;
}
