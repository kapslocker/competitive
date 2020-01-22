#include <bits/stdc++.h>
using namespace std;

#define int long long

bool isgreater(int a, int b) {
    for(int i = 0; i < 60; i++) {
        int x = 1ll << i, y = a & x, z = b & x;
        if(y && !z)
            return true;
    }
    return false;
}
int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, ans = 0;
    cin >> n;
    vector<vector<bool> > graph(n, vector<bool>(n, 0));
    vector<pair<int, int32_t> > input(n);
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int32_t i = 0; i < n; i++) {
        cin >> b[i];
    }
    for(int32_t i = 0; i < n; i++) {
        input[i].first = a[i];
        input[i].second = b[i];
    }
    vector<int32_t> degs(n, 0);
    for(int32_t i = 0; i < n; i++) {
        for(int32_t j = 0; j < n; j++) {
            if(isgreater(input[i].first, input[j].first)) {
                graph[i][j] = true;
                degs[i]++;
            }
        }
    }
    set<int32_t> candidates;
    for(int32_t i = 0; i < n; i++) {
        candidates.insert(i);
    }
    int32_t curr = n;
    while(true) {
        bool found = false;
        int node = -1;
        for(int32_t x : candidates) {
            if(degs[x] == curr - 1) {
                found = true;
                curr--;
                node = x;
                for(int32_t y : candidates) {
                    if(graph[y][x]) {
                        graph[y][x] = false;
                        degs[y]--;
                    }
                }
            }
        }
        if(!found)
            break;
        candidates.erase(node);
    }
    for(int32_t x : candidates) {
        ans += input[x].second;
    }
    cout << ans << endl;
    return 0;
}
