//--- Problem Statement ---

/*Given a Binary Search Tree (with all values unique) and two node values. Find the Lowest Common Ancestors of the two nodes in the BST.*/

//--- Solution ---

void search(Node* root, const int& n1, const int& n2, Node*& ans)
{
    if(!ans)
    {
        if(root->data>n1 && root->data>n2)
        {
            if(root->left)
                search(root->left, n1, n2, ans);
        }
        else if(root->data<n1 && root->data<n2)
        {
            if(root->right)
                search(root->right, n1, n2, ans);
        }
        else
            ans=root;
    }
}
Node* LCA(Node *root, int n1, int n2)
{
   //Your code here
    Node* ans=nullptr;
    search(root, n1, n2, ans);
    return ans;
}
