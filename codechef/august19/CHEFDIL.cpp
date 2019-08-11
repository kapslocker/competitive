#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
      string str;
      cin >> str;
      int count = 0;
      for(int j = 0; j < str.length(); j++) {
        count += str[j] == '1';
      }
      if(count % 2) {
        cout << "WIN" << endl;
      }
      else {
        cout << "LOSE" << endl;
      }
    }
    return 0;
}
