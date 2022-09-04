//--- Problem Statement ---

/*Given a Binary Search Tree and a range [low, high]. Find all the numbers in the BST that lie in the given range.
Note: Element greater than or equal to root go to the right side.*/

//--- Solution ---

void inorder(Node* root, const int& low, const int& high, vector<int>& ans)
{
    if(root->data<low)
    {
        if(root->right)
            inorder(root->right, low, high, ans);
        return ;
    }
    else if(root->data>high)
    {
        if(root->left)
            inorder(root->left, low, high, ans);
        return ;
    }
    else
    {
        if(root->left)
            inorder(root->left, low, high, ans);
        ans.push_back(root->data);
        if(root->right)
            inorder(root->right, low, high, ans);
    }
}
vector<int> printNearNodes(Node *root, int low, int high) {
    //code here
    vector<int> ans;
    inorder(root, low, high, ans);
    return ans;
}
