#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, party = 0, total = 0;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i < n; i++) {
        cin >> arr[i];
        total += arr[i];
    }
    vector<int> myset;
    myset.push_back(1);
    party += arr[0];
    for(int i = 1; i < n; i++) {
        if(2 * arr[i] <= arr[0]) {
            myset.push_back(i + 1);
            party += arr[i];
        }
    }
    if(2 * party <= total) {
        cout << 0 << endl;
        return 0;
    }
    cout << myset.size() << endl;
    for(int i = 0; i < myset.size(); i++) {
        cout << myset[i] << " ";
    }
    cout << endl;
}