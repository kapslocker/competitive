#include <bits/stdc++.h>
using namespace std;

map<vector<int>, vector<vector<int> > > graph;

int diff(vector<int> &prev, vector<int> &add) {
    unordered_set<int> st;
    for(int &x : prev)
        st.insert(x);
    for(int &y : add)
        if(st.find(y) == st.end())
            return y;
    return -1;
}

void dfs(vector<int> &ans, vector<int> &u) {
    vector<int> v = graph[u][0];
    ans.push_back(diff(v, u));
    for(auto &x : graph[v]) {
        if(x != u) {
            ans.push_back(diff(x, v));
            continue;
        }
    }
    for(int i = 0; i < 3; i++) {
        bool found = false;
        for(int j = 0; j < 2; j++) {
            if(u[i] == ans[j])
                found = true;
        }
        if(!found) {
            ans.push_back(u[i]);
        }
    }
    stack<vector<int> > st;
    st.push(graph[u][0]);
    map<vector<int>, bool> visited;
    vector<int> prev = u;
    visited[u] = true;
    while(!st.empty()) {
        v = st.top();
        st.pop();
        ans.push_back(diff(prev, v));
        visited[v] = true;
        prev = v;
        for(auto &x: graph[v]) {
            if(!visited[x]) {
                st.push(x);
            }
        }
    } 
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<vector<int> > arr(n - 2, vector<int>(3, 0));
    map<pair<int, int>, vector<int> > hmap;
    for(int i = 0; i < n - 2; i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
        sort(arr[i].begin(), arr[i].end());
        int a = arr[i][0];
        int b = arr[i][1];
        int c = arr[i][2];
        hmap[{a, b}].push_back(c);
        hmap[{a, c}].push_back(b);
        hmap[{b, c}].push_back(a);
    }
    for(int i = 0; i < n - 2; i++) {
        vector<int> u = arr[i];
        int a = u[0];
        int b = u[1];
        int c = u[2];
        if(hmap[{a, b}].size() > 1) {
            vector<int> n1 = {a, b, hmap[{a, b}][0]};
            vector<int> n2 = {a, b, hmap[{a, b}][1]};
            sort(n1.begin(), n1.end());
            sort(n2.begin(), n2.end());
            if(u != n1)
                graph[u].push_back(n1);
            if(u != n2)
                graph[u].push_back(n2);
        }
        if(hmap[{b, c}].size() > 1) {
            vector<int> n1 = {b, c, hmap[{b, c}][0]};
            vector<int> n2 = {b, c, hmap[{b, c}][1]};
            sort(n1.begin(), n1.end());
            sort(n2.begin(), n2.end());
            if(u != n1)
                graph[u].push_back(n1);
            if(u != n2)
                graph[u].push_back(n2);

        }
        if(hmap[{a, c}].size() > 1) {
            vector<int> n1 = {a, c, hmap[{a, c}][0]};
            vector<int> n2 = {a, c, hmap[{a, c}][1]};
            sort(n1.begin(), n1.end());
            sort(n2.begin(), n2.end());
            if(u != n1)
                graph[u].push_back(n1);
            if(u != n2)
                graph[u].push_back(n2);

        }
    }
    vector<int> source;
    for(auto &[u, v]: graph) {
        if(v.size() == 1) {
            source = u;
            break;
        }
    }
    vector<int> ans;
    dfs(ans, source);
    for(int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
