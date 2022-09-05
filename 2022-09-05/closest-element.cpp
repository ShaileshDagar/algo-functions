//--- Problem Statement ---

/*Given a BST and an integer. Find the least absolute difference between any node value of the BST and the given integer.*/

//--- Solution ---

void solve(Node* root, int& k, int& ans)
{
    if(root==nullptr)
        return ;
    ans=min(ans, abs(k-(root->data)));
    if(ans==0)
        return ;
    else if(root->data>k)
        solve(root->left, k, ans);
    else
        solve(root->right, k, ans);
}
//Function to find the least absolute difference between any node
//value of the BST and the given integer.
int minDiff(Node *root, int k)
{
    //Your code here
    int ans=INT_MAX;
    solve(root, k, ans);
    return ans;
}
