#include <iostream>
#include <queue>
#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int val)
    {
        left = NULL;
        right = NULL;
        data = val;
    }
};

// build Binary search tree

node *insertIntoBst(node *root, int d)
{
    if (root == NULL)
    {
        root = new node(d);
        return root;
    }

    if (d > root->data)
    {
        root->right = insertIntoBst(root->right, d);
    }

    else
    {
        root->left = insertIntoBst(root->left, d);
    }
    return root;
}

void takeInput(node *&root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        root = insertIntoBst(root, data);
        cin >> data;
    }
}

// level order traversal
void levelOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;

            if (!q.empty())
            {
                q.push(NULL);
            }
        }

        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

//  search BST
bool searchInBst(node *root, int x)
{
    if (root == NULL)
        return false;

    if (root->data == x)
        return true;

    if (root->data > x)
        return searchInBst(root->left, x);

    else
        return searchInBst(root->right, x);
}

// Find predecessor and successor inorder

// GOG solution
node *maximumNode(node *root)
{
    while (root->right)
    {
        root = root->right;
    }
    return root;
}

node *miniVal(node *root)
{
    if (root->left == NULL)
        return root;
    return miniVal(root->left);
}

void findPredecessor(node *root, node *&pred, int key)
{
    // base case
    if (root == NULL)
    {
        pred = NULL;
        return;
    }

    // if the root is our key node then the predecessor will be the largest node in its left subtree
    if (root->data == key)
    {
        if (root->left != NULL)
        {
            pred = maximumNode(root->left);
        }
    }

    // if our key value is less than the root node value then we'll search in left subtree for key node
    else if (key < root->data)
    {
        findPredecessor(root->left, pred, key);
    }

    // if our key value is more than the root node value then we'll search in right subtree for key node
    else if (key > root->data)
    {
        // update predecessor to the current node before recursing in the right subtree
        pred = root;
        findPredecessor(root->right, pred, key);
    }
    return;
}

// Predecessor and succesor combined
pair<int, int> predecessorSuccessor(node *root, int key)
{
    // find key
    node *temp = root;
    int pre = -1;
    int succ = -1;

    while (temp->data != key)
    {

        if (temp->data > key)
        {
            succ = temp->data;
            temp = temp->left;
        }

        if (temp->data < key)
        {
            pre = temp->data;
            temp = temp->right;
        }
    }

    // predecessor and successor

    node *leftTree = temp->left;
    while (leftTree != NULL)
    {
        pre = leftTree->data;
        leftTree = leftTree->right;
    }

    node *rightTree = temp->right;
    while (rightTree != NULL)
    {
        succ = rightTree->data;
        rightTree = rightTree->left;
    }

    pair<int, int> ans = make_pair(pre, succ);
    return ans;
}

// Deletion in BST

node *deleteFromBst(node *root, int val)
{

    if (root == NULL)
    {
        return root;
    }

    if (root->data == val)
    {

        // 0  child
        if (root->left == NULL || root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // 1  child
        if (root->left != NULL && root->right == NULL)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }
        if (root->left == NULL && root->right != NULL)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }

        // 2  child
        if (root->left != NULL || root->right != NULL)
        {
            int mini = (miniVal(root->right))->data;
            root->data = mini;
            root->right = deleteFromBst(root->right, mini);
            return root;
        }
    }

    else if (root->data < val)
    {
        root->left = deleteFromBst(root->left, val);
        return root;
    }

    else if (root->data > val)
    {
        root->right = deleteFromBst(root->right, val);
        return root;
    }
}
//  check bst or not
bool validateBST(node *root, int min, int max)
{
    return isBST(root, INT_MIN, INT_MAX);
}

bool isBST(node *root, int min, int max)
{

    if (root == NULL)
    {
        return true;
    }

    if (root->data >= min && root->data <= max)
    {
        bool left = isBST(root->left, min, root->data);
        bool right = isBST(root->right, root->data, max);
        return left && right;
    }

    else
        return false;
}

// kth smallest node in BST

int solveBst(node *root, int &i, int k)
{
    if (root == NULL)
        return -1;

    int left = solveBst(root->left, i, k);

    if (left != -1)
    {
        return left;
    }
    i++;

    if (i == k)
        return root->data;

    return solveBst(root->right, i, k);
}

int kthSmallest(node *root, int k)
{
    int i = 0;
    return solveBst(root, i, k);
}

// LCA in BST

node *lCAinBst(node *root, node *a, node *b)
{

    if (root == NULL)
    {
        return NULL;
    }

    if (root->data < a->data && root->data < b->data)
    {
        return lCAinBst(root->right, a, b);
    }

    if (root->data > a->data && root->data > b->data)
    {
        return lCAinBst(root->left, a, b);
    }

    return root;
}

// Two sum in BST
void inorder(node *root, vector<int> &in)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

bool twoSumInBST(node *root, int target)
{
    vector<int> inorderVal;
    inorder(root, inorderVal);

    int i = 0;
    int j = inorderVal.size() - 1;
    while (i < j)
    {
        int sum = inorderVal[i] + inorderVal[j];
        if (sum == target)
            return true;
        else if (sum > target)
            j--;
        else
            i++;
    }
    return false;
}

// flatten a BST into sorted linked list
node *flatten(node *root)
{
    vector<int> inorderVal;
    inorder(root, inorderVal);

    int n = inorderVal.size();
    node *main = new node(inorderVal[0]);
    node *curr = main;

    for (int i = 1; i < n; i++)
    {
        node *temp = new node(inorderVal[i]);
        curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }
    curr->left = NULL;
    curr->right = NULL;

    return main;
}

// convert normal BST into balanced BST
void inorder(node *root, vector<int> &in)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

node *inorderToBst(int s, int e, vector<int> inorderVal)
{
    if (s > e)
    {
        return NULL;
    }

    int mid = (s + e) / 2;
    node *temp = new node(inorderVal[mid]);
    temp->left = inorderToBst(s, mid - 1, inorderVal);
    temp->right = inorderToBst(mid + 1, e, inorderVal);
    return temp;
}

node *balancedBst(node *root)
{
    vector<int> inorderVal;
    inorder(root, inorderVal);

    return inorderToBst(0, inorderVal.size() - 1, inorderVal);
}

// preorder to binary tree
node *solvePreorder(vector<int> &preorder, int min, int max, int &i)
{

    if (i >= preorder.size())
        return NULL;

    if (preorder[i] < min || preorder[i] > max)
    {
        return NULL;
    }

    node *root = new node(preorder[i++]);
    root->left = solvePreorder(preorder, min, root->data, i);
    root->right = solvePreorder(preorder, root->data, max, i);

    return root;
}

node *preorderBST(vector<int> &preorder)
{
    int mini = INT_MIN;
    int maxi = INT_MAX;
    int i = 0;
    return solvePreorder(preorder, mini, maxi, i);
}

// Merge two BST into One
vector<int> mergeArrays(vector<int> a, vector<int> b)
{
    vector<int> ans(a.size() + b.size());

    int i = 0, j = 0;
    int k = 0;
    while (i < a.size() && j < b.size())
    {
        if (a[i] < b[j])
        {
            ans[k++] = a[i];
            i++;
        }
        else
        {
            ans[k++] = b[j];
            j++;
        }
    }
    while (i < a.size())
    {
        ans[k++] = a[i];
    }

    while (j < b.size())
    {
        ans[k++] = b[j];
    }

    return ans;
}

node *mergeBST(node *root1, node *root2)
{
    vector<int> bst1, bst2;
    inorder(root1, bst1);
    inorder(root2, bst2);

    vector<int> mergeArray = mergeArrays(bst1, bst2);
    int s = 0, e = mergeArray.size() - 1;
    return inorderToBst(s, e, mergeArray);
}

// Flatten a binary tree using doubly linked list
void convertIntoDll(node *root, node *head)
{

    if (root == NULL)
    {
        return;

        convertIntoDll(root->right, head);
        root->right = head;
        if (head != NULL)
        {
            head->left = root;
        }

        head = root;
        convertIntoDll(root->left, head);
    }
}

node *mergeLinkedList(node *&head1, node *&head2)
{

    node *head = NULL;
    node *tail = NULL;

    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data < head2->data)
        {
            if (head == NULL)
            {
                tail = head1;
                tail = head1;
                head1 = head1->right;
            }
            else
            {
                tail->right = head1;
                head->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        }
        else
        {
            if (head == NULL)
            {
                head = head2;
                tail = head2;
                head1 = head2->right;
            }

            else
            {
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }

    while (head1 != NULL)
    {
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }

    while (head2 != NULL)
    {
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }
    return head;
}

int countNodes(node *head)
{
    int cnt = 0;
    node *temp = head;
    while (temp != NULL)
    {
        cnt++;
        temp = temp->right;
    }
    return cnt;
}

node *sortedDllToBst(node *&head, int n)
{
    int n = countNodes(head);
    if (n <= 0 || head == NULL)
    {
        return NULL;
    }
    node *left = sortedDllToBst(head, n / 2);
    node *root = head;
    root->left = left;
    head = head->right;
    root->right = sortedDllToBst(root->right, (n - n / 2 - 1));
    return root;
}

node *mergeBst2(node *root1, node *root2)
{

    node *head1 = NULL;
    convertIntoDll(root1, head1);
    head1->left = NULL;

    node *head2 = NULL;
    convertIntoDll(root2, head2);
    head2->left = NULL;

    node *head = mergeLinkedList(head1, head2);
    int n = countNodes(head);
    sortedDllToBst(head, n);
    return head;
}

// Largest BST in a Binary tree
/*
class info {
public:
  int maxi;
  int mini;
  bool isBST;
  int size;
};

info solve(TreeNode<int> *root, int &ans) {
  if (root == NULL) {
    return {INT_MIN, INT_MAX, true, 0};
  }
  info left = solve(root->left, ans);
  info right = solve(root->right, ans);

  info currNode;

  currNode.size = left.size + right.size + 1;
  currNode.maxi = max(root->data,right.maxi);
  currNode.mini = min(root->data,left.mini);

  if (left.isBST && right.isBST &&
      (root->data > left.maxi && root->data < right.mini))
    currNode.isBST = true;

  else
    currNode.isBST = false;

  if (currNode.isBST) {
    ans = max(ans, currNode.size);
  }
  return currNode;
}

int largestBST(TreeNode<int> *root) {
  int maxSize = 0;
  info temp = solve(root, maxSize);
  return maxSize;
}


*/

int main()
{
    node *root = NULL;
    cout << "Enter data to create BST" << endl;
    takeInput(root);
    // cout << "Printing the BST" << endl;
    // levelOrderTraversal(root);

    // // for pred and success

    // // Here we'll take input x and then find it's predecessor
    // int x;
    // cin >> x;
    // node *pred = NULL;

    // findPredecessor(root, pred, x);

    // // -1 will always be the first node in Inorder traversal because we are taking input BST till -1
    // // that means the node with predecessor -1 is the first node in Inorder traversal
    // if (pred->data != -1)
    //     cout << "The predecessor of node " << x << " is " << pred->data;
    // else
    //     cout << "The predecessor of node doesn't exist";

    return 0;
}

//  Merge BSTs to Create Single BST

void collectNodes(unordered_map<int, TreeNode *> &mp, TreeNode *node)
{

    if (!node)
        return;
    mp[node->val] = node;
    collectNodes(mp, node->left);
    collectNodes(mp, node->right);
}

void makeTree(unordered_map<int, TreeNode *> &mp, TreeNode *&node, int &cnt)
{

    if (!node)
        return;
    if (!node->left && !node->right && mp[node->val])
    {
        node = mp[node->val];
        mp[node->val] = NULL;
        cnt++;
    }
    makeTree(mp, node->left, cnt);
    makeTree(mp, node->right, cnt);
}

bool validateBST(TreeNode *root, TreeNode *low, TreeNode *high)
{

    if (!root)
        return true;
    if ((low && root->val <= low->val) ||
        (high && root->val >= high->val))
        return false;

    return validateBST(root->left, low, root) &&
           validateBST(root->right, root, high);
}

public:
TreeNode *canMerge(vector<TreeNode *> &trees)
{

    if (trees.size() == 1)
    {
        return validateBST(trees[0], NULL, NULL) ? trees[0] : NULL;
    }

    unordered_map<int, TreeNode *> mp;
    for (auto &node : trees)
    {
        collectNodes(mp, node->left);
        collectNodes(mp, node->right);
    }

    TreeNode *root = NULL;
    for (auto &node : trees)
    {
        if (mp.count(node->val))
            mp[node->val] = node;
        else if (root)
            return NULL;
        else
            root = node;
    }

    if (!root)
        return NULL;

    int cnt = 0;
    makeTree(mp, root, cnt);
    if (cnt != mp.size())
        return NULL;

    return validateBST(root, NULL, NULL) ? root : NULL;
}

// Maximum Sum BST in Binary Tree
class info
{
public:
    int maxi;
    int mini;
    bool isBST;
    int sum;
};

info solve(TreeNode *root, int &ans)
{
    // base case
    if (root == NULL)
    {
        return {INT_MIN, INT_MAX, true, 0};
    }

    info left = solve(root->left, ans);
    info right = solve(root->right, ans);

    info currNode;

    currNode.sum = left.sum + right.sum + root->val;
    currNode.maxi = max(root->val, right.maxi);
    currNode.mini = min(root->val, left.mini);

    if (left.isBST && right.isBST && (root->val > left.maxi && root->val < right.mini))
    {
        currNode.isBST = true;
    }
    else
    {
        currNode.isBST = false;
    }

    // answer update
    if (currNode.isBST)
    {
        ans = max(ans, currNode.sum);
    }

    return currNode;
}
int maxSumBST(TreeNode *root)
{
    int maxSum = 0;
    info temp = solve(root, maxSum);
    return maxSum;
}

// Minimum Distance Between BST Nodes

void inorder(TreeNode *root, vector<int> &in)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left, in);
    in.push_back(root->val);
    inorder(root->right, in);
}
int minDiffInBST(TreeNode *root)
{
    vector<int> in;
    inorder(root, in);
    int mini = INT_MAX;
    for (int i = 0; i < in.size() - 1; i++)
    {
        mini = min(mini, in[i + 1] - in[i]);
    }

    return mini;
}

// Populate Inorder Successor of all nodes of a Binary Tree

void inorder(TreeNode<int> *root, TreeNode<int> *&prev)
{

    if (root == NULL)
        return;

    inorder(root->right, prev);
    root->next = prev;
    prev = root;
    inorder(root->left, prev);
}

void inorderSuccessor(TreeNode<int> *root)
{
    TreeNode<int> *prev = NULL;
    inorder(root, prev);
}

// Find Mode in Binary Search Tree

unordered_map<int, int> map;

void solve(TreeNode *root)
{
    if (!root)
        return;

    map[root->val]++;

    if (root->left)
        solve(root->left);

    if (root->right)
        solve(root->right);
}

vector<int> findMode(TreeNode *root)
{
    solve(root);
    int m = INT_MIN;
    int mf = 0;

    for (auto x : map)
    {
        if (x.second >= mf)
        {
            m = x.first;
            mf = x.second;
        }
    }
    vector<int> v;

    for (auto x : map)
    {
        if (x.second == mf)
        {
            v.push_back(x.first);
        }
    }
    return v;
}

// Range Sum of BST

int sum = 0;
void inorder(TreeNode *root, int low, int high)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left, low, high);

    if (root->val >= low && root->val <= high)
        sum += root->val;

    inorder(root->right, low, high);
}

int rangeSumBST(TreeNode *root, int low, int high)
{

    inorder(root, low, high);
    return sum;
}

// Verify Preorder Serialization of a Binary Tree

bool isValidSerialization(string preorder)
{
    int nodes = 1;
    preorder += ',';
    for (int i = 0; i < preorder.size(); i++)
    {
        if (preorder[i] != ',')
            continue; // comma seperated values of nodes
        nodes--;      // after taking each node decrease value of left nodes
        if (nodes < 0)
            return false;
        if (preorder[i - 1] != '#')
            nodes += 2; // if current node is not null means it will 2 childs si increase by 2;
    }
    return nodes == 0;
}

// Zigzag Conversion

string convert(string s, int numRows) {
    
    if(numRows <= 1) return s;

    vector<string>v(numRows, ""); 

    int j = 0, dir = -1;

    for(int i = 0; i < s.length(); i++)
    {

        if(j == numRows - 1 || j == 0) dir *= (-1); 
		 
        v[j] += s[i];

        if(dir == 1) j++;

        else j--;
    }

    string res;

    for(auto &it : v) res += it; 

    return res;

    }

// Convert BST to Greater Tree

int s=0;
void solve(TreeNode* root){
        if(!root)
        return;
        if(!root->left and !root->right){
            s+=root->val;
            root->val=s;
            return;
            
        }
        solve(root->right);
        s+=root->val;
        root->val=s;
        
        solve(root->left);                
    }
TreeNode* convertBST(TreeNode* root) {
       if(!root)
        return NULL;

        solve(root);
        return root; 
    }

// Recover Binary Search Tree

class Solution {
  TreeNode* first, *last, *prev;
public:
    void inorder(TreeNode* root){
        if(root==NULL) return;
        inorder(root->left);
        if(prev!=NULL && (root->val<prev->val)){
            if(first==NULL){
                first=prev;
                last=root; 
            }
            else
                last=root;
        }
        prev=root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        first=last=prev=NULL;
        inorder(root);
        swap(first->val,last->val);
    }
};

// Unique Binary Search Trees II

vector<TreeNode*> generateTrees(int n) {
        if (n == 0) {
            return vector<TreeNode*>();
        }
        
        unordered_map<string, vector<TreeNode*>> memo;

        return generateTreesHelper(1, n, memo);        
    }
vector<TreeNode*> generateTreesHelper(int start, int end, unordered_map<string, vector<TreeNode*>>& memo) {
        string key = to_string(start) + "-" + to_string(end);
        if (memo.find(key) != memo.end()) {
            return memo[key];
        }
        
        vector<TreeNode*> trees;
        if (start > end) {
            trees.push_back(nullptr);
            return trees;
        }
        
        for (int rootVal = start; rootVal <= end; rootVal++) {
            vector<TreeNode*> leftTrees = generateTreesHelper(start, rootVal - 1, memo);
            vector<TreeNode*> rightTrees = generateTreesHelper(rootVal + 1, end, memo);
            
            for (TreeNode* leftTree : leftTrees) {
                for (TreeNode* rightTree : rightTrees) {
                    TreeNode* root = new TreeNode(rootVal);
                    root->left = leftTree;
                    root->right = rightTree;
                    trees.push_back(root);
                }
            }
        }
        
        memo[key] = trees;
        return trees;
    }    

// 