//--- Problem Statement ---
/*Given a binary tree with a value associated with each node, 
we need to choose a subset of these nodes such that sum of chosen nodes is maximum 
under a constraint that no two chosen node in subset should be directly connected that is, 
if we have taken a node in our sum then we can’t take its any children or parents in consideration and vice versa.*/

//--- Solution ---

pair<int, int> answer(Node* root)
{
    int s1s2, s1ns2, s2ns1, ns1ns2;
    pair<int, int> p, pl, pr;
    pl = {0,0};
    pr = {0,0};
    if(root->left)
        pl=answer(root->left);
    if(root->right)
        pr=answer(root->right);

    s1s2 = pl.first + pr.first;
    s1ns2 = pl.first + pr.second;
    s2ns1 = pr.first + pl.second;
    ns1ns2 = pl.second + pr.second;

    p.first = root->data + pl.second + pr.second;
    p.second = max(max(s1s2, ns1ns2), max(s1ns2, s2ns1));

    return p;
}
int getMaxSum(Node *root) 
{
    // Add your code here
    pair<int, int> ans = answer(root);
    return max(ans.first, ans.second);
}
