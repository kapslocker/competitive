#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, a, b;
    cin >> n >> m;
    vector<pair<int, int> > arr;
    bool visit[101] = {false};
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        if(a != 0 && !visit[a]){
            cout << "NO\n";
            return 0;
        }
        for(int j = a; j <= b; j++)
            visit[j] = true;
    }
    for(int i = 0; i <= m; i++){
        if(!visit[i]){
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}
