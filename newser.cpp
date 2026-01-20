#include <bits/stdc++.h>
using namespace std;


 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

string serialize(TreeNode* root) {
        string x ="";
        if(!root) return "null,";
        x = x.append(to_string(root->val) + ",") + serialize(root->left) + serialize(root->right);
        return x;
}
TreeNode* build(queue<string>& q){
    string val = q.front();
    q.pop();

    if(val == "null") return nullptr;

    TreeNode* node = new TreeNode(stoi(val));
    node->left = build(q);
    node->right = build(q);
    
    return node;
}

TreeNode* deserialize(string data) {
    queue<string> q;
    string token;

    for (char c : data) {
        if (c == ',') {
            q.push(token);
            token.clear();
        } else {
            token += c;
        }
    }

    return build(q);
}


void printTree(TreeNode* root) {
    if (!root) return;

    cout << "Root: " << root->val << endl;

    cout << "Left side: ";
    TreeNode* curr = root->left;
    while (curr) {
        cout << curr->val << " ";
        curr = curr->left;
    }
    cout << endl;

    cout << "Right side: ";
    curr = root->right;
    while (curr) {
        cout << curr->val << " ";
        curr = curr->right;
    }
    cout << endl;
}


int main() {
    TreeNode* root = new TreeNode(44);
    TreeNode* curr = root;
    for(int i = 1; i<=5; i++){
        curr->left = new TreeNode(44 - i);
        curr = curr->left;
    }
    curr = root;
    for(int i =1; i<5; i++){
        curr->right = new TreeNode(44+i);
        curr = curr->right;
    }
    // printTree(root);
    string x = serialize(root);
    cout<<x<<" ";

    return 0;
}