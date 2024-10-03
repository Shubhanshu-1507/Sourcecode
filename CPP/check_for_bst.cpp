#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


class Solution {
    bool isBSTHelper(Node* root, int minRange, int maxRange) {
        if(!root) return true;
        
        bool isLeftSubTreeBST = isBSTHelper(root->left, minRange, root->data);
        bool isRightSubTreeBST = isBSTHelper(root->right, root->data, INT_MAX);
        
        if(root->data <= minRange or root->data >= maxRange) {
            return false;
        }
        
        return isLeftSubTreeBST && isRightSubTreeBST;
    }
    
  public:
    bool isBST(Node* root) {
        return isBSTHelper(root, INT_MIN, INT_MAX);
    }
};


Node* buildTree(string str) {
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    Node* root = new Node(stoi(ip[0]));

    queue<Node*> queue;
    queue.push(root);

    int i = 1;
    while (!queue.empty() && i < ip.size()) {
        Node* currNode = queue.front();
        queue.pop();
        string currVal = ip[i];

        if (currVal != "N") {
            currNode->left = new Node(stoi(currVal));
            queue.push(currNode->left);
        }

        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        if (currVal != "N") {
            currNode->right = new Node(stoi(currVal));
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

void inorder(Node* root, vector<int>& v) {
    if (root == NULL)
        return;

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        if (ob.isBST(root))
            cout << "true\n";

        else
            cout << "false\n";
    }
    
    return 0;
}