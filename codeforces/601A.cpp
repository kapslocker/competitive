#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <map>
#include <set>
using namespace std;

int main() {
    int n, m, u, v, c;
    cin >> n >> m;
    vector<int> colors(n + 1);
    map<int, set<int> > graph;
    for(int i = 0; i < n; i++) {
        cin >> c;
        colors[i+1] = c;
    }
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        int a = colors[u], b = colors[v];
        if(a == b)
            continue;
        if(graph[a].find(b) == graph[a].end())
            graph[a].insert(b);
        if(graph[b].find(a) == graph[b].end())
            graph[b].insert(a);
    }
    int maxcol = 0, maxcard = INT_MIN, col;
    for(auto &pt:graph) {
        col = pt.first;
        int temp = (pt.second).size();
        if(temp > maxcard) {
            maxcard = temp;
            maxcol = col;
        }
    }
    if(maxcol == 0) {
        int mincol = INT_MAX;
        for(int i = 1; i <= n; i++) {
            if(colors[i] < mincol)
                mincol = colors[i];
        }
        cout << mincol << endl;
        return 0;
    }
    cout << maxcol << endl;
    return 0;
}
