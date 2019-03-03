#include <iostream>
#include <vector>

using namespace std;

int main() {
    string str;
    cin >> str;
    int n = str.length(), i = 4, j = n - 1;
    vector<char> curr = {'h', 'e', 'l', 'l', 'o'};
    bool found = true;
    while(found) {
        while(j >= 0 && str[j] != curr[i])
            j--;
        if(j < 0)
            found = false;
        else {
            i--;
            j--;
            if(i == -1)
                break;
        }
    }
    if(!found)
        cout << "NO\n";
    else
        cout << "YES\n";
    return 0;
}
