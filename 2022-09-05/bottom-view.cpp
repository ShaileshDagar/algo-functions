//--- Problem Statement ---

/*Given a binary tree, print the bottom view from left to right.
A node is included in bottom view if it can be seen when we look at the tree from bottom.*/

//--- Solution ---

void travel(Node* root, int& max_l, int& max_r, int d=0)
{
    if(root==nullptr)
        return ;
    max_l=min(max_l, d);
    max_r=max(max_r, d);
    travel(root->left, max_l, max_r, d-1);
    travel(root->right, max_l, max_r, d+1);
}
void levelorder(Node* root, vector<int> v[], int d)
{
    queue<pair<Node*, int>> q;
    q.push({root, d});
    while(!q.empty())
    {
        v[q.front().second].push_back(q.front().first->data);
        if(q.front().first->left)
            q.push({q.front().first->left, q.front().second-1});
        if(q.front().first->right)
            q.push({q.front().first->right, q.front().second+1});
        q.pop();
    }
}
vector <int> bottomView(Node *root) {
    // Your Code Here
    vector<int> ans;
    int max_l=0,max_r=0;
    travel(root, max_l, max_r);
    int w = max_r+abs(max_l)+1;
    vector<int> v[w];
    levelorder(root, v, abs(max_l));
    for(int i=0; i<w; i++)
    {
        ans.push_back(v[i].back());
    }
    return ans;
}
