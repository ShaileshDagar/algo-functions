//--- Problem Statement ---
/*Given an array of size N that can be used to represents a tree. 
The array indexes are values in tree nodes and array values give the parent node of that particular index (or node). 
The value of the root node index would always be -1 as there is no parent for root. 
Construct the standard linked representation of Binary Tree from this array representation.*/

//--- Solution ---

void maketree(const int parent[], int i, Node* tree[], Node* child)
{
    if(tree[i]==nullptr)
    {
        tree[i] = new Node(i);
        if(child)
        {
            tree[i]->left = child;
        }
        if(parent[i]!=-1)
            maketree(parent, parent[i], tree, tree[i]);
    }
    else
    {
        if(tree[i]->left==nullptr)
            tree[i]->left=child;
        else
            tree[i]->right=child;
    }
    return ;
}
Node *createTree(int parent[], int n)
{
    // Your code here
    Node* tree[n] = {};
    Node* root;
    for(int i=0; i<n; i++)
    {
        if(tree[i]==nullptr)
            maketree(parent, i, tree, nullptr);
        if(parent[i]==-1)
            root=tree[i];
    }
    return root;
}
