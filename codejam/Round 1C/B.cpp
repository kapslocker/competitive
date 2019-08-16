#include <bits/stdc++.h>
using namespace std;

int N = 596;

void solve() {
    // first letter
    vector<char> arr(596, '$');
    string ans;
    map<char, int> c1, c2, c3, c4, taken;
    for(int i = 1; i < N; i+= 5) {
        cout << i << endl << flush;
        cin >> arr[i];
        c1[arr[i]]++;
    }
    for(char ch = 'A'; ch <= 'E'; ch++) {
        if(c1[ch] < 24) {
            ans = ans + ch;
            taken[ch] = true;
            break;
        }
    }

    set<int> indices;
    for(int i = 1; i < N; i+=5) {
        if(arr[i] == ans[0]) {
            indices.insert(i);
        }
    }
    // second letter
    for(int i : indices) {
        cout << i + 1 << endl << flush;
        cin >> arr[i+1];
        c2[arr[i+1]]++;
    }
    for(char ch = 'A'; ch <= 'E'; ch++) {
        if(taken.find(ch) != taken.end())
            continue;
        if(c2[ch] < 6) {
            ans = ans + ch;
            taken[ch] = true;
            break;
        }
    }
    indices.clear();
    for(int i = 1; i < N; i+=5) {
        if(arr[i+1] == ans[1]) {
            indices.insert(i + 1);
        }
    }
    // third
    for(int i : indices) {
        cout << i + 1 << endl << flush;
        cin >> arr[i+1];
        c3[arr[i+1]]++;
    }
    for(char ch = 'A'; ch <= 'E'; ch++) {
        if(taken.find(ch) != taken.end())   continue;
        if(c3[ch] < 2) {
            ans = ans + ch;
            taken[ch] = true;
            break;
        }
    }
    // fourth
    for(int i : indices) {
        if(arr[i+1] == ans[2]) {
            cout << i + 2 << endl << flush;
            cin >> arr[i+2];
            c4[arr[i+2]]++;
        }
    }
    for(char ch = 'A'; ch <= 'E'; ch++) {
        if(taken.find(ch) != taken.end())   continue;
        if(c4[ch] == 1) {
            ans = ans + ch;
            taken[ch] = true;
            break;
        }
    }
    for(char ch = 'A'; ch <= 'E'; ch++) {
        if(taken.find(ch) == taken.end()) {
            ans = ans + ch;
            break;
        }
    }
    swap(ans[3], ans[4]);
    cout << ans << endl << flush;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t, f;
    cin >> t >> f;
    for(int tt = 0; tt < t; tt++) {
        solve();
        char resp;
        cin >> resp;
        if(resp == 'N')  return 0;
    }
    return 0;
}
