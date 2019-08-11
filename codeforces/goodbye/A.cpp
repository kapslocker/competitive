#include <iostream>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.length();
    int count = 0;
    bool seen[5] = {0};

    for(int i = 0; i < n; i++){
        char ch = s[i];
        if('0' <= ch && ch <= '9'){
            int x = ch - '0';
            if(x % 2 != 0){
                count++;
            }
        }
        else{
            if(ch == 'a' ||ch == 'e' ||ch == 'i' ||ch == 'o' ||ch == 'u' ){
                count++;
            }
        }
    }
    cout << count << endl;
    return 0;
}
