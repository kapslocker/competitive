#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int type;
    Node *left, *right;
    Node(int x) {
        left = NULL;
        right = NULL;
        type = x;
    }
};

bool insert(stack<Node*> &st, int type) {
    if(st.size() == 0)
        return false;
    Node *u = st.top();
    st.pop();
    u->type = type;
    if(u->type == 1) {
        u->left = new Node(0);
        u->right = new Node(0);
        st.push(u->right);
        st.push(u->left);
        return true;
    }
    return true;
}

bool check(Node *root) {
    if(!root)
        return true;
    if(root->type == 0)
        return false;
    return check(root->left) && check(root->right);
}

bool build(Node *root) {
    if(!root) {
        return true;
    }
    if(root->type == 1) {
        cout << "pair<";
        bool a = build(root->left);
        if(!a)
            return false;
        cout << ",";
        a = build(root->right);
        cout << ">";
        return a;
    }
    cout << "int";
    return true;
}



int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    string s;
    cin >> n;
    Node *root = new Node(0);
    stack<Node*> st;
    st.push(root);
    while(cin >> s) {
        bool a;
        if(s == "int") {
            a = insert(st, 2);
        }
        else {
            a = insert(st, 1);
        }
        if(a == false) {
            cout << "Error occurred\n";
            return 0;
        }
    }
    string ans;
    if(!check(root)) {
        cout << "Error occurred\n";
        return 0;
    }
    build(root);
    cout << endl;
    return 0;
}
