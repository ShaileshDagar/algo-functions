//--- Problem Statement ---

/*Given the root of a binary tree. Check whether it is a BST or not.
Note: We are considering that BSTs can not contain duplicate Nodes.
A BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.*/

//--- Solution ---

bool check(Node* root, bool& ans, int mine, int maxe)
{
    if(root==nullptr)
        return ans;
    else
        ans=(root->data>mine) && (root->data<maxe);
    if(ans==false)
        return ans;
    if(root->left)
        ans=(root->left->data)<root->data;
    if(ans==false)
        return ans;
    if(root->right)
        ans=(root->right->data)>root->data;
    if(ans==false)
        return ans;
    return check(root->left, ans, mine, root->data) && check(root->right, ans, root->data, maxe);
}
bool isBST(Node* root) 
{
    // Your code here
    bool ans=true;
    return check(root, ans, INT_MIN, INT_MAX);
}
