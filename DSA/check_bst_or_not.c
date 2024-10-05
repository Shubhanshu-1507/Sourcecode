#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data){
    struct node *n; // creating a node pointer
    n = (struct node *) malloc(sizeof(struct node)); // Allocating memory in the heap
    n->data = data; // Setting the data
    n->left = NULL; // Setting the left and right children to NULL
    n->right = NULL; // Setting the left and right children to NULL
    return n; // Finally returning the created node
}

void preOrder(struct  node* root){
    if(root!=NULL){
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(struct  node* root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

void inOrder(struct  node* root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int isBST(struct node* root)
{
   static struct node *prev= NULL; // it will be null for only main root. so take static it will get updated. 
    if(root!=NULL)  // if root is not equal to null . tree must not be null
    {
       if(!isBST(root->left)) // then check for left subtree if it is bst or not
       {
        return 0;// return false if left subtree is not  bst
       }
       if(prev!=NULL && root-> data <= prev-> data) // if previous of any node of bst is not null && data of p2 <= data p3 . prev not equal to null is for first main root bcz its previous is null. // simple hai previous not null ye root node ke liye hai taki root ka data kisi aur se chota na ho paaey, and baaki nodes ke liye prev not equal null hoga but node ka data kabhi previous ke data se bda nhi ho paaeyga.
    {
      return 0; // return false bcz the if condition is not for bst. checking it in inorder traversal.
    }
     prev =root; 
     return isBST(root->right); // check for right subtree
    }

    else
    {
        return 1; // since empty tree is always a bst
    }
    
}

int main(){
     
    // Constructing the root node - Using Function (Recommended)
    struct node *root = createNode(5);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(4);
    // Finally The tree looks like this:
    //      5
    //     / \
    //    3   6
    //   / \
    //  1   4  

    // Linking the root node with left and right children
    root->left = p1;
    root->right = p2;
    p1->left = p3;
    p1->right = p4;

    // preOrder(p);
    // printf("\n");
    // postOrder(p); 
    // printf("\n");
    inOrder(root);
    printf("\n");
    // printf("%d\n", isBST(root)); 
    // int n = isBST(root);
    // printf("%d\n",n);
    if(isBST(root))
    {
        printf("This is a bst" );
    }
    else
    {
        printf("This is not a bst");
    }
    return 0;
}