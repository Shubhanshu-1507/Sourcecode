#include <iostream>
#include <cstdlib>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data) {
    Node* n = new Node();
    n->data = data;
    n->left = nullptr;
    n->right = nullptr;
    return n;
}

void preOrder(Node* root) {
    if (root != nullptr) {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(Node* root) {
    if (root != nullptr) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}

void inOrder(Node* root) {
    if (root != nullptr) {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

int isBST(Node* root) {
    static Node* prev = nullptr;
    if (root != nullptr) {
        if (!isBST(root->left)) {
            return 0;
        }
        if (prev != nullptr && root->data <= prev->data) {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    } else {
        return 1;
    }
}

int main() {
    Node* root = createNode(5);
    Node* p1 = createNode(3);
    Node* p2 = createNode(6);
    Node* p3 = createNode(1);
    Node* p4 = createNode(4);

    root->left = p1;
    root->right = p2;
    p1->left = p3;
    p1->right = p4;

    inOrder(root);
    cout << endl;

    if (isBST(root)) {
        cout << "This is a bst";
    } else {
        cout << "This is not a bst";
    }

    return 0;
}
