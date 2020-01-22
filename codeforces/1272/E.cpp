#include <bits/stdc++.h>
using namespace std;

vector<int> odd, even;

void multibfs(map<int, vector<int> > &graph, vector<int> &arr) {
    int n = arr.size();
    queue<int> q;
    for(int i = 0; i < n; i++) {
        if(arr[i] % 2) {
            q.push(i);
            odd[i] = 0;
        }
    }
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int v : graph[u]) {
            int before = odd[v];
            odd[v] = min(odd[v], odd[u] + 1);
            if(before != odd[v]) {
                q.push(v);
            }
        }
    }
    for(int i = 0; i < n; i++) {
        if(arr[i] % 2 == 0) {
            q.push(i);
            even[i] = 0;
        }
    }
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int v : graph[u]) {
            int before = even[v];
            even[v] = min(even[v], even[u] + 1);
            if(even[v] != before) {
                q.push(v);
            }
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    odd.resize(n, INT_MAX);
    even.resize(n, INT_MAX);
    map<int, vector<int> > graph;
    for(int i = 0; i < n; i++) {
        int u = i - arr[i], v = i + arr[i];
        if(u >= 0) {
            graph[u].push_back(i);
        }
        if(v < n) {
            graph[v].push_back(i);
        }
    }
    multibfs(graph, arr);
    for(int i = 0; i < n; i++) {
        if(arr[i] % 2) {
            cout << (even[i] == INT_MAX ? -1 : even[i]) << " ";
        }
        else {
            cout << (odd[i] == INT_MAX ? -1 : odd[i]) << " ";
        }
    }
    cout << endl;
    return 0;
}
