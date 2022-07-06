//--- Problem Staement ---
/*Given a Binary Tree, print the diagonal traversal of the binary tree.
Consider lines of slope -1 passing between nodes.
Given a Binary Tree, print all diagonal elements in a binary tree belonging to same line.*/

//---Solution ---

vector<int> diagonal(Node *root)
{
    vector<int> ans;
    Node* curr=nullptr;
    queue<Node*> lnodes;
    lnodes.push(root);
    while(curr!=nullptr || !lnodes.empty())
    {
        if(curr==nullptr)
        {
            curr=lnodes.front();
            lnodes.pop();
        }
        ans.push_back(curr->data);
        if(curr->left!=nullptr)
            lnodes.push(curr->left);
        curr=curr->right;
    }
    return ans;
}
